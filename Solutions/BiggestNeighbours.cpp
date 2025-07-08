#pragma once
#include <iostream>
#include <vector>

//Ограничение времени 1 секунда
//Ограничение памяти 64Mb
//
//Ввод стандартный ввод или input.txt
//Вывод стандартный вывод или output.txt
//
//Дан список чисел.Определите, сколько в этом списке элементов, которые больше двух своих соседей и выведите количество таких элементов.
//
//Формат ввода
//Вводится список чисел.Все числа списка находятся на одной строке.
//
//Формат вывода
//Выведите ответ на задачу.

class BiggestNeighbours
{
public:
    static void find() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int64_t numPrior;
        std::cin >> numPrior;
        int64_t numCurrent;
        bool priorIsBigger = false;
        size_t counter = 0;

        while (std::cin >> numCurrent)
        {
            if(numCurrent > numPrior)
                priorIsBigger = true;
            else if (priorIsBigger && numPrior > numCurrent)
                ++counter;
            numPrior = numCurrent;
        }

        std::cout << counter;
    }
};

