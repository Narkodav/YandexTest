#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>

//���������� �����
//
//��������� ���� ����� �������� ������� ���������� ������� ��������, �������������� ��������� �������� :
//
//���������� ����� �������.������ ����� �� �����.������ ������� ������� �� �����.
// ������� ����� ����� ������� ��������.���������� ��������� ���� ��������.
//
//��� ���������� ����������� ����� �������.������� ����� ���������������� �������(���������� ������, �� ���������� ��������).
// ������������� � ����� ��� �� ������ �������.
// ��� ������ ��� ������� ���������� �������� ����������, ������ ��� �������� �����, ��� ��������� ���� � ������� ��������.
// ��� ���������� �������� ���������� ������ � ���� ������.
// ����� �� ����� ����� ���� ��� �������������, ��� � �������������, ��� ���� ������ �������� ����� ������.
//
//������ �����
//������� ���� �������� ������������������ ��������.�������� ��������� �������� : 
// DEPOSIT name sum - ��������� ����� sum �� ���� ������� name. ���� � ������� ��� �����, �� ���� ���������.
// WITHDRAW name sum - ����� ����� sum �� ����� ������� name. ���� � ������� ��� �����, �� ���� ���������.
// BALANCE name - ������ ������� ������� �� ����� ������� name.
// TRANSFER name1 name2 sum - ��������� ����� sum �� ����� ������� name1 �� ���� ������� name2. ���� � ������ - ���� ������� ��� �����, �� ��� ��������� ����.
// INCOME p - ��������� ���� ��������, � ������� ������� �����, p% �� ����� �����.
// �������� ����������� ������ �������� � ������������� �������� �� �����, ���� � ������� ������� �������������, �� ��� ���� �� ��������.
// ����� ���������� ��������� ����� �� ����� �������� �����, �� ���� ����������� ������ ����� ����� �������� ������.
// ������� ����� ����������� ��������� �������������.
//
//������ ������
//��� ������� ������� BALANCE ��������� ������ ������� ������� �� ����� ������� �������.
// ���� �� � ������� � ������������� ������ �� ������ ���� � �����, �������� ERROR.

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

