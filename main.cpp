#include "Autocomplete.h"


int main()
{
	setlocale(LC_ALL, "");
	struct TrieNode* root = getNewNode();

	// ������� ������� �������
	std::vector<std::string> words ={"alex", "apple", "baby", "boy", "console", "children", "hello", "help"};

	// ��������� ������
	for (auto& w : words)
		insert(root, w);

	bool exit = false;
	char operation;
	int res;
	std::string prefix;
	std::string addToDictionary;

	while (!exit)
	{
		bool isValid = true;
		std::cout << "\n�������� ��������:\n" <<
			"1 - ������� ������ ����� ��� ��������������\n" <<
			"2 - �������� ����� � �������\n" <<
			"3 - �����" << std::endl;
		std::cin >> operation;
		switch (operation)
		{
		case '1':
			std::cout << "\n������� ������� (�������� �����): " << std::endl;
			std::cin >> prefix;
			for (size_t i = 0; i < prefix.length(); i++)
			{
				if (prefix[i] < 'a' || prefix[i] > 'z')
				{
					std::cout << "�������� �������. �� ������ ������ ������� ������� �������� �� ���������� �����\n";
					isValid = false;
					break;
				}
			}
			if (isValid)
			{
				std::cout << "\n�������������� ����: " << std::endl;
				res = printAutoComplete(root, prefix);

				if (res == 0)
					std::cout << "������ ���� � ���� ��������� �� �������\n";
				else if (res == -1)
					std::cout << "����� � ���� ��������� �� �������\n";
			}
			break;
		case '2':
			std::cout << "\n�������� �����: " << std::endl;
			std::cin >> addToDictionary;
			for (size_t i = 0; i < addToDictionary.length(); i++)
			{
				if (addToDictionary[i] < 'a' || addToDictionary[i] > 'z')
				{
					std::cout << "�������� �����. �� ������ ������ ������� ������� �������� ���������� �����\n";
					isValid = false;
					break;
				}
			}
			if (isValid)
			{
				insert(root, addToDictionary);
			}
			break;
		case '3':
			exit = true;
			break;
		default:
			std::cout << "\n�������� ��� ��������! ���������� ��� ���." << std::endl;
			break;
		}
	}
	return 0;
}