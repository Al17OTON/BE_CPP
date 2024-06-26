﻿// RESTAPI.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "RESTAPI.h"
#include <string>
#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include "src/util/UrlParser.hpp"
#include "src/httpmapper/Mapper.hpp"

using tcp = boost::asio::ip::tcp;
namespace http = boost::beast::http;

void handleRequest(http::request<http::string_body>& request, tcp::socket& socket);
void runServer();

int main() {
    try {
        runServer();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


void handleRequest(http::request<http::string_body>& request, tcp::socket& socket) {
    std::cout << request.base() << "\n";

    std::cout << "url " << request.target() << "\n";

    for (auto&& f : request) {
        std::cout << f.name_string() << ": " << f.value() << "\n";
    }

    std::pair<std::string, std::string> tmp = getFirstPath(request.target());

    std::cout << tmp.first << " " << tmp.second << "\n";

    Mapper& mapper = Mapper::Instance();
    IController& con = mapper.getController(tmp.first);
    con.proceed("test", request, socket);
}


void runServer() {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, { tcp::v4(), 8080 });
    
    std::cout << tcp::v4().protocol() << "\n";

    while (true) {
        tcp::socket socket(io_context);
        acceptor.accept(socket);

        // Read the HTTP request
        boost::beast::flat_buffer buffer;
        http::request<http::string_body> request;
        boost::beast::http::read(socket, buffer, request);

        // Handle the request
        handleRequest(request, socket);

        // Close the socket
        socket.shutdown(tcp::socket::shutdown_send);
    }
}
