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

// проверка класса kpm::Stack
int main()
{
	std::cout << "\tStack\n";

	// стек
	kpm::Stack <TYPE> my_stack;

	// переменная для записи команды
	char command;
	
	std::cout << "Enter 'h' for help.\n";

	for (;;) try
	{
		std::cout << "\nEnter command:\n";
		std::cout << "> ";

		// ввод команды
		std::cin >> command;

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

		// добавить ключ на вершину стека
		case 'a':
			{
				// буфер для ключа, помещаемого на вершину стека
				TYPE buf;

				// ввод данных
				std::cin >> buf;

				// поместить ключ на вершину стека
				my_stack.Push(buf); 

				std::cout << buf << " is placed.\n";
			};
			break;

		// удалить ключ с вершины стека
		case 'd':
			std::cout << my_stack.Top() << " exempted.\n";
			my_stack.Pop();
			break;
			
		// возвращает ключ на вершине стека
		case 't':
			{
				TYPE buf = my_stack.Top();
				std::cout << buf << " on top.\n";
			};
			break;

		// возвращает true, если стек пустой, иначе - false
		case 'e':
			if (my_stack.Empty())
			{
				std::cout << "Stack is empty.\n";
			}
			else
			{
				std::cout << "Stack is not empty.\n";
			};
			break;

		// возвращает количество ключей стека
		case 's':
			std::cout << my_stack.Size() << " keys in stack.\n";
			break;

		// очистить стек
		case 'c':
			my_stack.Clear();
			std::cout << "Stack cleared.\n";
			break;

		// выход из программы 
		case 'q':                              
			return 0;

		default:
			{
				throw kpm::Stack_info("Error! Unknown command!\n");
			}
		};
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
}

