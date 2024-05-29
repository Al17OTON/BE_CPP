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
	/// Meyer's Singleton 기법을 활용한 싱글톤 패턴
	/// 멀티 스레드 환경에서 싱글톤 패턴은 thread-safe하지 않다.
	/// 다음과 같은 방법으로 싱글톤을 보장한다.
	/// </summary>
	/// <returns>싱글톤 객체</returns>
	static Mapper& Instance() {
		static Mapper m;	// static 변수는 다음에 재호출되어도 사라지지 않고 남아있는다. 따라서 싱글톤이다.
		return m;
	}

	IController& getController(const std::string& name);
};


#endif