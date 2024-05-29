#ifndef ICONTROLLER_H
#define ICONTROLLER_H
#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
using tcp = boost::asio::ip::tcp;
namespace http = boost::beast::http;

class IController {
public:
	virtual void proceed(const std::string& path, http::request<http::string_body>& request, tcp::socket& socket) = 0;

	virtual void sendDefault(const std::string& path, http::request<http::string_body>& request, tcp::socket& socket) = 0;
};

#endif