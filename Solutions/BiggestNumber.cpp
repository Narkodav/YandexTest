#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//����������� ������� 0.5 �������
//����������� ������ 64Mb
//
//���� ����������� ���� ��� input.txt
//����� ����������� ����� ��� output.txt
//
//������� ������ ������ �������� � ���� �������� �����.���� �����.����� ����������, ����� ����� ������� ����� ����� �� ��� ���������.
//
//������ �����
//� ������ ������ �������� n � ���������� �����.��� �� ����������� 100. 
// �� ������ ������ ����� ������ �������� n ��������������� �����, ������ �� ������� �� ����������� 1000.
//
//������ ������
//����� ������� ����� ������� �����, ������� ����� ��������� �� ������ �����.

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

