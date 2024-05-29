#include "Mapper.hpp"

Mapper::Mapper() {
	std::cout << "Mapper Init \n";
}

Mapper::~Mapper() {
	std::cout << "Mapper deleted \n";
}

/// <summary>
/// �־��� �̸��� ���� ��Ʈ�ѷ��� ã�� ��ȯ�Ѵ�.
/// ���� ���ٸ� nullptr��ȯ
/// </summary>
/// <param name="name">ã�� ��Ʈ�ѷ��� path</param>
/// <returns>��Ʋ�ѷ� ��ü</returns>
IController& Mapper::getController(const std::string& name) {
	if (name.compare("user")) {
		return UserController::Instance();
	}

	//�� const ������ ���� �ʱⰪ�� lvalue���� �Ѵ�. ��� ���� �ذ��� ���ؼ��� ������ ���� �ۼ��ؾ��Ѵ�.
	IController* lvalue = nullptr;
	return *lvalue;
}
