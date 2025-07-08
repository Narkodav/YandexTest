#pragma once
#include <iostream>
#include <vector>

//����������� ������� 1 �������
//����������� ������ 64Mb
//
//���� ����������� ���� ��� input.txt
//����� ����������� ����� ��� output.txt
//
//��� ������ �����.����������, ������� � ���� ������ ���������, ������� ������ ���� ����� ������� � �������� ���������� ����� ���������.
//
//������ �����
//�������� ������ �����.��� ����� ������ ��������� �� ����� ������.
//
//������ ������
//�������� ����� �� ������.

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

