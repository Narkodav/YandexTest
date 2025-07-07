#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

//������� - 1 (old)
//
//����������� ������� 1 �������
//����������� ������ 64Mb
//���� ����������� ���� ��� input.txt
//����� ����������� ����� ��� output.txt
//
//���� ����� ���������, ������������� ������������ ���� ������� ������������ � ��������� �������.
// � ���� ���� �������� ��������� ��� ������.
// �������� ���� ��� ������� ������� ����������, � ����� ������ �� ����� ����������, ���� �������� ������ �� �������.
// ������ ����� ���������� � �����, ���� � ��� ���� ���� �� ���� ������ �� �������� ����� �����.
//
//������ �����
//������� ������ ����� L - ���������� ������.����� ���� L ��� �����.
// ������ ������ � ���� - �������� �����.������ ������ - ������� �����.
// ����� ���� N - ����� ��������.������ ���� ���� �������.����� ���� ����� �� ����������� 200.
//
//������ ������
//��� ������� ������� �� ��������� ������ �������� ����� ������ ��������� ����� ������� � ������������������ �������.

struct languagePointer
{
	static std::vector<std::string> languages;
	size_t index;
};

std::vector<std::string> languagePointer::languages;

template<>
struct std::less<languagePointer>
{
	bool operator()(const languagePointer& left, const languagePointer& right) const {
		return std::less<std::string>()(
			languagePointer::languages[left.index],
			languagePointer::languages[right.index]);
	}
};

class Alphabet
{
public:
	static void find() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);

		size_t L;
		std::cin >> L;
		languagePointer::languages.resize(L);

		std::string buffer;
		buffer.reserve(200);

		std::unordered_multimap<char, size_t> charToLangMap;

		for (size_t i = 0; i < L; ++i)
		{
			std::cin >> languagePointer::languages[i] >> buffer;

			for (size_t j = 0; j < buffer.size(); ++j)
				charToLangMap.emplace(buffer[j], i);
		}

		size_t N;
		std::cin >> N;

		std::vector<std::set<languagePointer>> possibleLanguages(N);

		for (size_t i = 0; i < N; ++i)
		{
			std::cin >> buffer;
			for (size_t j = 0; j < buffer.size(); ++j)
			{
				auto range = charToLangMap.equal_range(buffer[j]);
				for (auto it = range.first; it != range.second; ++it)
					possibleLanguages[i].insert(languagePointer{ it->second });
			}
		}

		for (size_t i = 0; i < N; ++i)
		{
			for (auto& language : possibleLanguages[i])
				std::cout << languagePointer::languages[language.index] << ' ';
			std::cout << '\n';
		}
	}
};

