#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//Ограничение времени 0.5 секунды
//Ограничение памяти 64Mb
//
//Ввод стандартный ввод или input.txt
//Вывод стандартный вывод или output.txt
//
//Вечером ребята решили поиграть в игру «Большое число».Даны числа.Нужно определить, какое самое большое число можно из них составить.
//
//Формат ввода
//В первой строке записано n — количество чисел.Оно не превосходит 100. 
// Во второй строке через пробел записаны n неотрицательных чисел, каждое из которых не превосходит 1000.
//
//Формат вывода
//Нужно вывести самое большое число, которое можно составить из данных чисел.

class BiggestNumber
{
public:
    static void find() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        size_t N;
        std::cin >> N;
        std::vector<std::string> numbers(N);

        for(size_t i = 0; i < N; ++i) {
            std::cin >> numbers[i];
        }

        std::sort(numbers.begin(), numbers.end(), [](const std::string& a, const std::string& b) {
            return a + b > b + a;
        });

        for (size_t i = 0; i < N; ++i) {
            std::cout << numbers[i];
        }
    }
};

