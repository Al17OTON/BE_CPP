#pragma once
#ifndef URL_PARSER
#define URL_PARSER

#include <string>
#include <utility>

/// <summary>
/// �־��� ���ڰ� �ִ� �ε����� ã�Ƽ� ��ȯ
/// </summary>
/// <param name="str">���� ���ڿ�</param>
/// <param name="del">ã�� ����</param>
/// <returns>ã���� �ϴ� ������ �ε��� ���� ���ٸ� -1�� ��ȯ�Ѵ�.</returns>
int findDelIndex(const std::string& str, char del) {
	for (int idx = 1; idx < str.length(); idx++) {
		if (str.at(idx) == del) return idx;
	}
	return -1;
}

/// <summary>
/// �־��� url�� '/' ������ �ڸ���.
/// /abc/def/ghi�� �־����ٸ�
/// abc , /def/ghi�� �������ش�.
/// </summary>
/// <param name="path">���</param>
/// <returns>first = �θ� ����� �̸�, second = ���� ���</returns>
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