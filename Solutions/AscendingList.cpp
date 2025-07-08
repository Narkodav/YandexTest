#pragma once
#include <iostream>
#include <vector>

//����������� ������� 1 �������
//����������� ������ 64Mb
//
//���� ����������� ���� ��� input.txt
//����� ����������� ����� ��� output.txt
//
//��� ������.����������, �������� �� �� ��������� ������������
// (�� ���� ����� ��, ��� ������ ������� ����� ������ ������ �����������).
//
//�������� YES, ���� ������ ��������� ���������� � NO � ��������� ������.

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

