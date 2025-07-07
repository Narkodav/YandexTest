#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>

//Банковские счета
//
//Некоторый банк хочет внедрить систему управления счетами клиентов, поддерживающую следующие операции :
//
//Пополнение счета клиента.Снятие денег со счета.Запрос остатка средств на счете.
// Перевод денег между счетами клиентов.Начисление процентов всем клиентам.
//
//Вам необходимо реализовать такую систему.Клиенты банка идентифицируются именами(уникальная строка, не содержащая пробелов).
// Первоначально у банка нет ни одного клиента.
// Как только для клиента проводится операция пололнения, снятия или перевода денег, ему заводится счет с нулевым балансом.
// Все дальнейшие операции проводятся только с этим счетом.
// Сумма на счету может быть как положительной, так и отрицательной, при этом всегда является целым числом.
//
//Формат ввода
//Входной файл содержит последовательность операций.Возможны следующие операции : 
// DEPOSIT name sum - зачислить сумму sum на счет клиента name. Если у клиента нет счета, то счет создается.
// WITHDRAW name sum - снять сумму sum со счета клиента name. Если у клиента нет счета, то счет создается.
// BALANCE name - узнать остаток средств на счету клиента name.
// TRANSFER name1 name2 sum - перевести сумму sum со счета клиента name1 на счет клиента name2. Если у какого - либо клиента нет счета, то ему создается счет.
// INCOME p - начислить всем клиентам, у которых открыты счета, p% от суммы счета.
// Проценты начисляются только клиентам с положительным остатком на счету, если у клиента остаток отрицательный, то его счет не меняется.
// После начисления процентов сумма на счету остается целой, то есть начисляется только целое число денежных единиц.
// Дробная часть начисленных процентов отбрасывается.
//
//Формат вывода
//Для каждого запроса BALANCE программа должна вывести остаток на счету данного клиента.
// Если же у клиента с запрашиваемым именем не открыт счет в банке, выведите ERROR.

class BankAccounts
{
	using IntType = int64_t;
	using AccountMap = std::unordered_map<std::string, IntType>;

	static inline AccountMap::iterator getAccount(AccountMap& accounts, const  std::string& name)
	{
		auto it = accounts.find(name);
		if (it == accounts.end())
			return accounts.emplace_hint(it, name, 0);
		else return it;
	}

public:

	static void find() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);

		AccountMap accounts;

		std::fstream input("input.txt", std::ios::in);
		std::fstream output("output.txt", std::ios::out);

		if (!input.is_open() || !output.is_open())
			throw std::runtime_error("input or output file not open");

		std::string buffer;
		IntType intBuffer;
		buffer.reserve(10);

		while (input.good())
		{
			input >> buffer;
			if (buffer == "DEPOSIT")
			{
				input >> buffer;
				auto it = getAccount(accounts, buffer);
				input >> intBuffer;
				it->second += intBuffer;
			}
			else if (buffer == "WITHDRAW")
			{
				input >> buffer;
				auto it = getAccount(accounts, buffer);
				input >> intBuffer;
				it->second -= intBuffer;
			}
			else if (buffer == "BALANCE")
			{
				input >> buffer;
				auto it = accounts.find(buffer);
				if (it != accounts.end())
					output << it->second << '\n';
				else output << "ERROR\n";
			}
			else if (buffer == "TRANSFER")
			{
				input >> buffer;
				auto it1 = getAccount(accounts, buffer);
				input >> buffer;
				auto it2 = getAccount(accounts, buffer);
				input >> intBuffer;
				it1->second -= intBuffer;
				it2->second += intBuffer;
			}
			else if (buffer == "INCOME")
			{
				input >> intBuffer;
				for (auto& account : accounts)
					if (account.second > 0)
						account.second += account.second * intBuffer / 100;
			}
			else throw std::runtime_error("invalid command");
		}
	}
};

