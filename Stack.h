///////////////////////////
// Автор:  Калинин Павел //
// Создан: 03.01.2019    //
///////////////////////////

#ifndef _STACK_H_
#define _STACK_H_

// пространство имен
namespace kpm
{
	/* 
		#####   класс "стек"   #####
		* реализован на односвязном списке
		* T1 - тип ключа
		* unsigned int - максимальный размер стека в байтах
	*/
	template <typename T1, unsigned int buffer>
	class Stack
	{
	private:
		// структура элемента стека
		struct stack_elem
		{
			// ключ
			T1 key;

			// указатель на следующий элемент стека
			Stack* next_elem;
		} m_stack_elem;

	public:
		// конструктор элемента стека
		Stack();

		// деструктор элемента стека
		~Stack();


	};

	template <typename T1, unsigned int buffer>
	Stack<T1, unsigned int>::Stack()
	{

	}


}

#endif /* _STACK_H_ */