#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

//Ограничение времени 1 секунда
//Ограничение памяти 64Mb
//
//Ввод стандартный ввод или input.txt
//Вывод стандартный вывод или output.txt
//
//Вася решил избавиться от проблем с произношением и стать певцом.Он обратился за помощью к логопеду.
// Тот посоветовал Васе выполнять упражнение, которое называется анаграммная группировка.
// В качестве подготовительного этапа нужно выбрать из множества строк анаграммы.
//
//Анаграммы –— это строки, которые получаются друг из друга перестановкой символов.Например, строки «SILENT» и «LISTEN» являются анаграммами.
//
//Помогите Васе найти анаграммы.
//
//Формат ввода
//В первой строке записано число n —– количество строк.Далее в строку через пробел записаны n строк.n не превосходит 6000. 
// Длина каждой строки не более 100 символов.
//
//Формат вывода
//Нужно вывести в отсортированном порядке индексы строк, которые являются анаграммами.
//
//Каждая группа индексов должна быть выведена в отдельной строке.Индексы внутри одной группы должны быть отсортированы по возрастанию.
// Группы между собой должны быть отсортированы по возрастанию первого индекса.
//
//Обратите внимание, что группа анаграмм может состоять и из одной строки.Например, если в исходном наборе нет анаграмм, то надо вывести n групп, каждая из которых состоит из одного индекса.

class Anagramm
{
public:
	static void find() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);

		std::string buffer;
		buffer.reserve(100);
		size_t n;
		std::cin >> n;

		std::vector<std::vector<size_t>> groups;
		groups.reserve(n);

		//assuming 256 possible chars, making a unique hash value for an unordered string would take up too much memory
		std::unordered_map<std::string, size_t> indicesMap;
		indicesMap.reserve(n);

		for(size_t i = 0 ; i < n; ++i)
		{
			std::cin >> buffer;
			std::sort(buffer.begin(), buffer.end());
			auto it = indicesMap.find(buffer);

			//no need to sort indices since they are automatically in an ascending order
			if (it == indicesMap.end())
			{
				indicesMap.emplace_hint(it, buffer, groups.size());
				groups.push_back({ i });
			}
			else groups[it->second].push_back(i);
		}
		
		for (size_t i = 0; i < groups.size(); ++i)
		{
			for (size_t j = 0; j < groups[i].size(); ++j)
				std::cout << groups[i][j] << ' ';
			std::cout << '\n';
		}	
	}
};

