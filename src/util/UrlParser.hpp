#pragma once
#ifndef URL_PARSER
#define URL_PARSER

#include <string>
#include <utility>

/// <summary>
/// 주어진 문자가 있는 인덱스를 찾아서 반환
/// </summary>
/// <param name="str">원본 문자열</param>
/// <param name="del">찾을 문자</param>
/// <returns>찾고자 하는 문자의 인덱스 만약 없다면 -1을 반환한다.</returns>
int findDelIndex(const std::string& str, char del) {
	for (int idx = 1; idx < str.length(); idx++) {
		if (str.at(idx) == del) return idx;
	}
	return -1;
}

/// <summary>
/// 주어진 url을 '/' 단위로 자른다.
/// /abc/def/ghi가 주어졌다면
/// abc , /def/ghi로 나누어준다.
/// </summary>
/// <param name="path">경로</param>
/// <returns>first = 부모 경로의 이름, second = 남은 경로</returns>
std::pair<std::string, std::string> getFirstPath(const std::string& path) {
	std::pair<std::string, std::string> p("", "");
	int idx = findDelIndex(path, '/');
	if (idx == -1) {
		p.first = path;
		p.second = "";
		return p;
	}

	p.first = path.substr(1, idx - 1);
	p.second = path.substr(idx);
	return p;
}
#endif