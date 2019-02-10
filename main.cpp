///////////////////////////
// Автор:  Калинин Павел //
// Файл:   main.cpp      //
// Создан: 03.01.2019    //
///////////////////////////

#include "Stack.h"      // описание стека
#include "Stack_info.h" // описание исключений
#include <iostream>

// определяет тип данных в стеке
#define TYPE std::string

//функция для проверки класса kpm::Stack
int main() try
{
	// стек
	kpm::Stack <TYPE> my_stack;

	// переменная для записи команды
	char command;

	for (;;)
	{
		std::cout << "\nEnter 'h' for help.\n";
		std::cout << "Enter the command:\n";
		std::cout << "> ";

		// ввод команды
		while(!(std::cin >> command));

		// операции со стеком
		switch (command)
		{
		// помощь
		case 'h':
			std::cout << "\n#######################   \n";
			std::cout <<   "\"a value\" - push(value) \n";
			std::cout <<   "      \"d\" - pop()       \n";
			std::cout <<   "      \"t\" - top()       \n";
			std::cout <<   "      \"e\" - empty()     \n";
			std::cout <<   "      \"s\" - size()      \n";
			std::cout <<   "      \"c\" - clear()     \n";
			std::cout <<   "#######################   \n";
			break;

		// добавить значение на вершину стека
		case 'a':
			{
				// буфер значения, помещаемого на вершину стека
				TYPE buf;

				// ввод данных
				while (!(std::cin >> buf));

				// поместить элемент на вершину стека
				my_stack.Push(buf); 
			};
			break;

		// удалить элемент с вершины стека
		case 'd':
			my_stack.Pop();
			break;
			
		// возвращает значение на вершине стека
		case 't':
			my_stack.Top();
			break;

		// возвращает true, если стек пустой, иначе - false
		case 'e':
			my_stack.Empty();
			break;

		// возвращает количество элементов стека
		case 's':
			my_stack.Size();
			break;

		// очистить стек
		case 'c':
			my_stack.Clear();
			break;

		// выход из программы 
		case 'q':                              
			return 0;

		default:
			{
				throw kpm::Stack_info("Error! Unknown command!\n");
			}
		};
	};

	system("pause");
	return 0;
}

// вывод информации по исключению
catch (const kpm::Stack_info& r_INFO)
{
	r_INFO.Print();
}

// неизвестное исключение
catch (...)
{
	std::cout << "Warning! Unknown exception caught!\n";
};
