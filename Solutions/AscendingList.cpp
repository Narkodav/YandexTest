#pragma once
#include <iostream>
#include <vector>

//Ограничение времени 1 секунда
//Ограничение памяти 64Mb
//
//Ввод стандартный ввод или input.txt
//Вывод стандартный вывод или output.txt
//
//Дан список.Определите, является ли он монотонно возрастающим
// (то есть верно ли, что каждый элемент этого списка больше предыдущего).
//
//Выведите YES, если массив монотонно возрастает и NO в противном случае.

class AscendingList
{
public:
    static void find() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int64_t numPrior;
        std::cin >> numPrior;
        int64_t numCurrent;

        while (std::cin >> numCurrent)
        {
            if (numCurrent <= numPrior)
            {
                std::cout << "NO";
                return;
            }
            numPrior = numCurrent;
        }
        std::cout << "YES";
    }
};

