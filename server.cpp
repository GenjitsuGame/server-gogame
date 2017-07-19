#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include "Goban.h"

using boost::asio::ip::tcp;

class session : public std::enable_shared_from_this<session> {
public:
    session(tcp::socket socket, Goban goban)
            : socket_(std::move(socket)), goban(goban) {
    }

    void start() {
        do_read();
    }

private:
    void do_read() {
        auto self(shared_from_this());
        socket_.async_read_some(boost::asio::buffer(data_, max_length),
                                [this, self](boost::system::error_code ec, std::size_t length) {
                                    if (!ec) {
                                        std::string command(this->data_);
                                        if (command.substr(0, 1) == "C") {
                                            goban = Goban(command.substr(1, 1023));
                                        } else {
                                            goban.editStone(
                                                    std::string(command.substr(1, Goban::SERIALIZED_MOVE_LENGTH)));
                                        }
                                    }
                                });
    }

    tcp::socket socket_;
    enum {
        max_length = 1024
    };
    Goban goban;
    char data_[max_length];
};

class server {
public:
    server(boost::asio::io_service &io_service, short port)
            : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)),
              socket_(io_service) {
        do_accept();
    }

private:
    void do_accept() {
        acceptor_.async_accept(socket_,
                               [this](boost::system::error_code ec) {
                                   if (!ec) {
                                       std::make_shared<session>(std::move(socket_), goban)->start();
                                   }

                                   do_accept();
                               });
    }

    Goban goban;
    tcp::acceptor acceptor_;
    tcp::socket socket_;
};

int main(int argc, char *argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: async_tcp_echo_server <port>\n";
            return 1;
        }

        boost::asio::io_service io_service;

        server s(io_service, std::atoi(argv[1]));

        io_service.run();
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}