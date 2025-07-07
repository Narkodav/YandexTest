#pragma once
#include <iostream>
#include <vector>

//Ограничение времени 1 секунда
//Ограничение памяти 64Mb
//
//Ввод стандартный ввод или input.txt
//Вывод стандартный вывод или output.txt
//
//Тимофей ищет место, чтобы построить себе дом.
// Улица, на которой он хочет жить, имеет длину n, то есть состоит из n одинаковых идущих подряд участков.
// Каждый участок либо пустой, либо на нём уже построен дом.
//
//Общительный Тимофей не хочет жить далеко от других людей на этой улице.
// Поэтому ему важно для каждого участка знать расстояние до ближайшего пустого участка.
// Если участок пустой, эта величина будет равна нулю — расстояние до самого себя.
//
//Помогите Тимофею посчитать искомые расстояния.Для этого у вас есть карта улицы.
// Дома в городе Тимофея нумеровались в том порядке, в котором строились, 
// поэтому их номера на карте никак не упорядочены.Пустые участки обозначены нулями.
//
//Формат ввода В первой строке дана длина улицы —– n(1 ≤ n ≤ 10 * *6).
// В следующей строке записаны n целых неотрицательных чисел — номера домов и обозначения пустых участков на карте(нули).
// Гарантируется, что в последовательности есть хотя бы один ноль.
// Номера домов(положительные числа) уникальны и не превосходят 109.
//
//Формат вывода Для каждого из участков выведите расстояние до ближайшего нуля.
// Числа выводите в одну строку, разделяя их пробелами.

class ClosestZero
{
    static size_t handleConsecutives(std::vector<size_t>& distances, size_t i, size_t N)
    {
        distances[i] = 1;
        size_t number = 0;
        size_t j = i + 1;
        for (; j < N; ++j)
        {
            std::cin >> number;
            if (number == 0)
            {
                size_t limit = (j - i) / 2;
                size_t k = 0;
                for (; k < limit; ++k)
                    distances[j - k - 1] = k + 1;
                return j;
            }
            else distances[j] = distances[j - 1] + 1;
        }
        return j;
    }

public:
    static void find() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        size_t N;
        size_t number;
        std::cin >> N;
        std::vector<size_t> distances(N);
        size_t i = 0;

        //handle first consecutives
        for (; i < N; ++i)
        {
            std::cin >> number;
            if (number == 0)
            {
                distances[i] = 0;
                for (size_t j = i - 1; j != std::numeric_limits<size_t>::max(); --j)
                    distances[j] = i - j;
                break;
            }
        }
        ++i;
        for (; i < N; ++i)
        {
            std::cin >> number;
            if (number == 0)
                distances[i] = 0;
            else i = handleConsecutives(distances, i, N);
        }

        for (size_t i = 0; i < N; ++i)
            std::cout << distances[i] << ' ';
    }
};

