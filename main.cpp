///////////////////////////
// Автор:  Калинин Павел //
// Создан: 03.01.2019    //
///////////////////////////

#include "Stack.h" // класс с описанием стека
#include "Stack_info.h" // классы для обработки ошибок, исключительных ситуаций, вывода отладочной информации
#include <iostream>

using namespace kpm;

/*
	функция для проверки класса kpm::Stack
*/
int main() try
{
	// стек из целочисленных элементов, ограничение - 1000 байт
	Stack <int, 1000> my_stack;

	// переменная для сохранения команды
	char command;

	// бесконечный цикл
	for (;;)
	{
		// ввод команды
		std::cout << "Enter the command:/n";
		std::cout << "> ";
		std::cin >> command;

		// операции со стеком
		switch (command)
		{
		case 'q': // выход из программы                                    <-----------------------   проверить 
			break; 
		default:
			throw Stack_info("Неизвестная команда\n");              // < ------------------------ переименовать
		};
	};
	
	return 0;
}
catch (const Stack_info& r_INFO)
{
	r_INFO.Print();
}
catch (...)
{
	std::cout << "Unknown exception caught!\n";
};