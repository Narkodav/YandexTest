#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <set>

//Быки и коровы
//
//Ограничение времени 1 секунда
//Ограничение памяти 256Mb
//
//Ввод стандартный ввод или input.txt
//Вывод стандартный вывод или output.txt
//
//Вася и Петя играют в игру «Быки и коровы».Вася загадал число состоящее из N цифр, а Петя пытается его отгадать.
// Петя называет число из N цифр, а Вася отвечает, сколько в нем «быков» и «коров».
//Количество «быков» вычисляется как количество цифр, стоящих на своем месте.
//Количество «коров» вычисляется как количество цифр, которые есть и загаданном Васей числе и в названном Петей, но стоят на разных местах.
// То есть эти цифры могут быть переставлены таким образом, чтобы стать «Быками».
//По загаданному Васей и названному Петей числам определите количество «быков» и «коров».
//
//Формат ввода
//Загаданное Васей и Петей числа положительные и вводятся по одному в строке.Количество цифр в числах не превосходит 1000. Числа не имеют ведущих нулей.
//
//Формат вывода
//В первой строке выведите количество «быков», а во второй — «коров».

class BullsAndCows
{
public:

    //this is probably how you are mean to solve it (maybe even using a set instead of sorting) O(NlogN)
    static void find() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::array<size_t, 10> existingSecretChars = { 0 };
        std::array<size_t, 10> existingGuessChars = { 0 };

        std::string secret, guess;
        std::cin >> secret >> guess;

        size_t bulls = 0, cows = 0;

        for(size_t i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                ++bulls;
            else
            {
                ++existingSecretChars[secret[i] - '0'];
                ++existingGuessChars[guess[i] - '0'];
            }
        }

        for (size_t i = 0; i < 10; i++) {
            cows += std::min(existingSecretChars[i], existingGuessChars[i]);
        }

        std::cout << bulls << " " << cows << std::endl;
    }
};

