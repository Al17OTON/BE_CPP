#include "UserController.hpp"

UserController::UserController() {
	std::cout << "user Controller init \n";
}

UserController::~UserController() {
	std::cout << "user Controller delete \n";
}

void UserController::proceed(const std::string& path, http::request<http::string_body>& request, tcp::socket& socket) {
	sendDefault(path, request, socket);
}

void UserController::sendDefault(const std::string& path, http::request<http::string_body>& request, tcp::socket& socket) {
    http::response<http::string_body> response;
    response.version(request.version());
    response.result(http::status::ok);
    response.set(http::field::server, "My HTTP Server");
    response.set(http::field::content_type, "text/plain");
    response.body() = "Default response";
    response.prepare_payload();

    // Send the response to the client
    boost::beast::http::write(socket, response);
}
