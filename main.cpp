#include "Autocomplete.h"


int main()
{
	setlocale(LC_ALL, "");
	struct TrieNode* root = getNewNode();

	// Создаем базовый словарь
	std::vector<std::string> words ={"alex", "apple", "baby", "boy", "console", "children", "hello", "help"};

	// Заполняем дерево
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
		std::cout << "\nВыберите операцию:\n" <<
			"1 - Введите начало слова для автозаполнения\n" <<
			"2 - Добавить слово в словарь\n" <<
			"3 - Выход" << std::endl;
		std::cin >> operation;
		switch (operation)
		{
		case '1':
			std::cout << "\nВведите префикс (строчные буквы): " << std::endl;
			std::cin >> prefix;
			for (size_t i = 0; i < prefix.length(); i++)
			{
				if (prefix[i] < 'a' || prefix[i] > 'z')
				{
					std::cout << "Неверный префикс. Вы должны ввести символы нижнего регистра на английском языке\n";
					isValid = false;
					break;
				}
			}
			if (isValid)
			{
				std::cout << "\nАвтодополнение слов: " << std::endl;
				res = printAutoComplete(root, prefix);

				if (res == 0)
					std::cout << "Других слов с этим префиксом не найдено\n";
				else if (res == -1)
					std::cout << "Слова с этим префиксом не найдены\n";
			}
			break;
		case '2':
			std::cout << "\nДобавить слово: " << std::endl;
			std::cin >> addToDictionary;
			for (size_t i = 0; i < addToDictionary.length(); i++)
			{
				if (addToDictionary[i] < 'a' || addToDictionary[i] > 'z')
				{
					std::cout << "Неверное слово. Вы должны ввести символы нижнего регистра английском языке\n";
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
			std::cout << "\nНеверный код операции! Попробуйте еще раз." << std::endl;
			break;
		}
	}
	return 0;
}