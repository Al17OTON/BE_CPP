#include "Mapper.hpp"

Mapper::Mapper() {
	std::cout << "Mapper Init \n";
}

Mapper::~Mapper() {
	std::cout << "Mapper deleted \n";
}

/// <summary>
/// 주어진 이름을 통해 컨트롤러를 찾아 반환한다.
/// 만약 없다면 nullptr반환
/// </summary>
/// <param name="name">찾을 컨트롤러의 path</param>
/// <returns>컨틀롤러 객체</returns>
IController& Mapper::getController(const std::string& name) {
	if (name.compare("user")) {
		return UserController::Instance();
	}

	//비 const 참조에 대한 초기값은 lvalue여야 한다. 라는 오류 해결을 위해서는 다음과 같이 작성해야한다.
	IController* lvalue = nullptr;
	return *lvalue;
}
