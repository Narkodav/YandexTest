#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <set>

//���� � ������
//
//����������� ������� 1 �������
//����������� ������ 256Mb
//
//���� ����������� ���� ��� input.txt
//����� ����������� ����� ��� output.txt
//
//���� � ���� ������ � ���� ����� � �������.���� ������� ����� ��������� �� N ����, � ���� �������� ��� ��������.
// ���� �������� ����� �� N ����, � ���� ��������, ������� � ��� ������ � ������.
//���������� ������ ����������� ��� ���������� ����, ������� �� ����� �����.
//���������� ������ ����������� ��� ���������� ����, ������� ���� � ���������� ����� ����� � � ��������� �����, �� ����� �� ������ ������.
// �� ���� ��� ����� ����� ���� ������������ ����� �������, ����� ����� �������.
//�� ����������� ����� � ���������� ����� ������ ���������� ���������� ������ � ������.
//
//������ �����
//���������� ����� � ����� ����� ������������� � �������� �� ������ � ������.���������� ���� � ������ �� ����������� 1000. ����� �� ����� ������� �����.
//
//������ ������
//� ������ ������ �������� ���������� ������, � �� ������ � ������.

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

