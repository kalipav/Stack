///////////////////////////
// Автор:  Калинин Павел //
// Файл:   Stack_info.h  //
// Создан: 03.01.2019    //
///////////////////////////

#ifndef _STACK_INFO_H_
#define _STACK_INFO_H_

#include <iostream>
#include <string>

namespace kpm
{
	// описание исключений
	class Stack_info
	{
	private:
		// строка
		std::string str;

	public:
		// конструктор, принимающий строку
		// const std::string& - строка с описанием исключения
		Stack_info(const std::string& r_STR)
		{
			str = r_STR;
		};

		// вывод описания исключения
		inline void Print() const
		{
			std::cout << str;
			system("pause");
		};
	};
}

#endif /* _STACK_INFO_H_ */