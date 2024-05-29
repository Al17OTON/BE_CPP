#pragma
#ifndef MAPPER_H
#define MAPPER_H

#include <iostream>
#include "../controller/IController.hpp"
#include "../user/controller/UserController.hpp"

class Mapper {
	Mapper();
	~Mapper();
public:

	/// <summary>
	/// Meyer's Singleton ����� Ȱ���� �̱��� ����
	/// ��Ƽ ������ ȯ�濡�� �̱��� ������ thread-safe���� �ʴ�.
	/// ������ ���� ������� �̱����� �����Ѵ�.
	/// </summary>
	/// <returns>�̱��� ��ü</returns>
	static Mapper& Instance() {
		static Mapper m;	// static ������ ������ ��ȣ��Ǿ ������� �ʰ� �����ִ´�. ���� �̱����̴�.
		return m;
	}

	IController& getController(const std::string& name);
};


#endif