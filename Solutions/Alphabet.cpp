#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

//Алфавит - 1 (old)
//
//Ограничение времени 1 секунда
//Ограничение памяти 64Mb
//Ввод стандартный ввод или input.txt
//Вывод стандартный вывод или output.txt
//
//Вася пишет программу, автоматически определяющую язык запроса пользователя в поисковую систему.
// У Васи есть алфавиты известных ему языков.
// Помогите Васе для каждого запроса определить, к каким языкам он может относиться, если смотреть только на алфавит.
// Запрос может относиться к языку, если в нем есть хотя бы один символ из алфавита этого языка.
//
//Формат ввода
//Сначала задано число L - количество языков.Далее идет L пар строк.
// Первая строка в паре - название языка.Вторая строка - алфавит языка.
// Далее идет N - число запросов.Потому идут сами запросы.Длина всех строк не превосходит 200.
//
//Формат вывода
//Для каждого запроса на отдельной строке выведите черех пробел возможные языки запроса в лексикографическом порядке.

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

