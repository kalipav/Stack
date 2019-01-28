///////////////////////////
// Автор:  Калинин Павел //
// Файл:   Stack.h       //
// Создан: 03.01.2019    //
///////////////////////////

#ifndef _STACK_H_
#define _STACK_H_

namespace kpm
{
	/* 
		#####   класс "стек"   #####
		* реализован на односвязном списке
		* T - тип ключа
	*/
	template <typename T>
	class Stack
	{
	private:
		// структура элемента стека
		struct stack_elem
		{
			// ключ
			T key;

			// указатель на следующий элемент стека
			Stack* next_elem;
		} m_stack_elem;

	public:
		// конструктор элемента стека, принимающий размер буфера под стек
		Stack(const unsigned int&);

		// деструктор элемента стека
		~Stack();
	};

	// конструктор элемента стека, принимающий размер буфера под стек
	// const unsigned int& - размер буфера 
	template <typename T>
	Stack<T>::Stack(const unsigned int& r_BUF_SIZE)
	{}

	// деструктор элемента стека
	template <typename T>
	Stack<T>::~Stack()
	{}
}

#endif /* _STACK_H_ */