#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H
#pragma once

#include "../../controller/IController.hpp"

class UserController : public IController {
	UserController();
	~UserController();
public:
	static UserController& Instance() {	//Meyer's Singleton
		static UserController uc;
		return uc;
	}

	void proceed(const std::string& path, http::request<http::string_body>& request, tcp::socket& socket);
	void sendDefault(const std::string& path, http::request<http::string_body>& request, tcp::socket& socket);
};


#endif
