///////////////////////////
// Автор:  Калинин Павел //
// Файл:   main.cpp      //
// Создан: 03.01.2019    //
///////////////////////////

#include "Stack.h"      // описание стека
#include "Stack_info.h" // описание исключений
#include <iostream>

//функция для проверки класса kpm::Stack
int main() try
{
	// стек из целочисленных элементов, ограничение - 1000 байт
	kpm::Stack <int> my_stack(1000);

	// переменная для хранения команды
	char command;

	for (;;)
	{
		// ввод команды
		std::cout << "Enter the command:\n";
		std::cout << "> ";
		std::cin >> command;

		// операции со стеком
		switch (command)
		{
		// добавить значение на вершину стека
		case 'p':

		// удаляет значение на вершине стека
		case 'd':

		// возвращает true, если стек пустой, иначе - false
		case 'e':

		// возвращает количество элементов стека
		case 's':

		// возвращает значение на вершине стека
		case 't':

		// выход из программы 
		case 'q':                              
			return 0;

		default:
			{
				throw kpm::Stack_info("Warning! Unknown command!\n");
			}
		};
	};
}

catch (const kpm::Stack_info& r_INFO)
{
	r_INFO.Print();
}

catch (...)
{
	std::cout << "Warning! Unknown exception caught!\n";
};