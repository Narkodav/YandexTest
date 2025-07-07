#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

//Ограничение времени 1 секунда
//Ограничение памяти 64Mb
//
//Ввод стандартный ввод или input.txt
//Вывод стандартный вывод или output.txt
//
//Напишите программу, которая находит в массиве элемент, самый близкий по величине к данному числу.
//
//Формат ввода
//В первой строке задается одно натуральное число N, не превосходящее 1000 – размер массива.
// Во второй строке содержатся N чисел – элементы массива(целые числа, не превосходящие по модулю 1000).
// В третьей строке вводится одно целое число x, не превосходящее по модулю 1000.
//
//Формат вывода
//Вывести значение элемента массива, ближайшее к x.Если таких чисел несколько, выведите любое из них.

class ClosestNumber
{
public:

    //this is probably how you are mean to solve it (maybe even using a set instead of sorting) O(NlogN)
    static void find(std::istream& input, std::ostream& output) {
        std::ios::sync_with_stdio(false);
        input.tie(nullptr);

        size_t N;
        input >> N;
        std::vector<int64_t> nums(N);

        for (size_t i = 0; i < N; ++i) {
            input >> nums[i];
        }

        int64_t x;
        input >> x;

        std::sort(nums.begin(), nums.end());
        auto it = std::lower_bound(nums.begin(), nums.end(), x);
        int64_t closest = nums[0];

        if (it == nums.begin()) {
            closest = nums.front();
        }
        else if (it == nums.end()) {
            closest = nums.back();
        }
        else {
            int64_t a = *(it - 1);
            int64_t b = *it;
            closest = (x - a <= b - x) ? a : b;
        }

        output << closest << '\n';
    }

    //this is actually faster for smaller dataset O(N)
    static void findLinear(std::istream& input, std::ostream& output) {
        std::ios::sync_with_stdio(false);
        input.tie(nullptr);

        size_t N;
        int64_t x;
        input >> N;
        std::vector<int64_t> nums(N);

        for (size_t i = 0; i < N; ++i) {
            input >> nums[i];
        }
        input >> x;

        int64_t closest = 0;
        int64_t minDiff = std::numeric_limits<int64_t>::max();

        for (int64_t num : nums) {
            if (num == x)
            {
                closest = x;
                break;
            }
            else if (num == closest) continue;

            int64_t diff = std::abs(num - x);

            if (diff < minDiff) {
                minDiff = diff;
                closest = num;
            }
        }

        output << closest << '\n';
    }
};

