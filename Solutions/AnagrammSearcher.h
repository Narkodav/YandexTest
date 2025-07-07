#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class AnagrammSearcher
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

