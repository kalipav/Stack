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
		// указатель на ключ
		T* m_p_key;

		// указатель на следующий элемент стека
		Stack* m_p_next_elem;

	public:
		// конструктор элемента стека
		Stack();

		// деструктор элемента стека
		~Stack();

		// поместить ключ на вершину стека
		void Push(const T& r_VALUE);

		// удалить ключ с вершины стека
		void Pop();

		// возвращает ключ на вершине стека
		T& Top() const;

		// возвращает true, если стек пустой, иначе - false
		bool Empty() const;

		// возвращает количество ключей в стеке
		int& Size() const;

		// очистить стек
		void Clear();
	};

	// конструктор элемента стека
	template <typename T>
	Stack<T>::Stack() :
	m_p_key(0x0),
	m_p_next_elem(0x0)
	{
		//std::cout << "The element is created.\n";
	}

	// деструктор элемента стека
	template <typename T>
	Stack<T>::~Stack()
	{
		// освободить указатель на ключ
		delete m_p_key;
		m_p_key = 0x0;

		// освободить указатель на следующий элемент стека
		delete m_p_next_elem;
		m_p_next_elem = 0x0;

		//std::cout << "The element exempted.\n";
	}

	// поместить ключ на вершину стека
	template <typename T>
	void Stack<T>::Push(const T& r_VALUE)
	{
		// если адрес ключа первого элемента 0x0, то выделить память под ключ
		if (m_p_key == 0x0)
		{
			m_p_key = new T(r_VALUE);
		}

		// иначе создать новый элемент стека
		else
		{
			// новый элемент
			Stack <T>* p_new_elem = new Stack <T>;

			// копируем адрес ключа элемента, который был вершиной
			p_new_elem->m_p_key = this->m_p_key;

			// копируем адрес элемента
			p_new_elem->m_p_next_elem = this->m_p_next_elem;

			// адрес нового ключа в вершине списка
			this->m_p_key = new T(r_VALUE);

			// адрес второго элемента списка
			this->m_p_next_elem = p_new_elem;
		};
	}

	// удалить ключ с вершины стека
	template <typename T>
	void Stack<T>::Pop()
	{
		// удаляемый ключ на вершине стека
		T temp_value;

		// если нет адреса ключа и адреса след. элемента - выход из метода
		if (this->m_p_key == 0x0 && this->m_p_next_elem == 0x0) 
		{
			return;
		}

		// если ключ один - удаляем его
		else if (this->m_p_key != 0x0 && this->m_p_next_elem == 0x0)
		{
			// удаляемый ключ на вершине стека
			temp_value = *this->m_p_key;

			delete this->m_p_key;
			this->m_p_key = 0x0;
		}

		else
		{
			// буферный указатель на второй элемент списка
			Stack <T>* p_next_elem = this->m_p_next_elem; 

			// удаляемый ключ на вершине стека
			temp_value = *this->m_p_key;

			// освобождаем указатель на ключ первого элемента
			delete this->m_p_key; 

			// копируем адрес ключа 2-го элемента
			this->m_p_key = p_next_elem->m_p_key; 

			// зануляем адрес ключа 2-го элемента, чтобы деструктор не освободил память
			p_next_elem->m_p_key = 0x0; 

			// копируем адрес следующего элемента 2-го элемента
			this->m_p_next_elem = p_next_elem->m_p_next_elem; 

			// зануляем адрес следующего элемента 2-го элемента, чтобы деструктор не освободил память
			p_next_elem->m_p_next_elem = 0x0; 

			// освобождаем указатель на 2-ой элемент
			delete p_next_elem; 
		};
	}

	// возвращает ключ на вершине стека
	// [out] T - ключ на вершине стека
	template <typename T>
	T& Stack<T>::Top() const
	{
		// вернуть ключ
		if (this->m_p_key != 0x0)
		{
			return *this->m_p_key;
		}

		// предотвращение разыменовывания нулевого указателя
		else
		{
			throw kpm::Stack_info("Error! NULL pointer!\n");
		};
	}

	// возвращает true, если стек пустой, иначе - false
	// [out] bool - true/false
	template <typename T>
	bool Stack<T>::Empty() const
	{
		// если нет ни одного ключа, вернуть true
		if (this->m_p_key == 0x0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// возвращает количество ключей в стеке
	// [out] int - количество ключей в стеке
	template <typename T>
	int& Stack<T>::Size() const
	{
		// счетчик
		int counter = 0;

		// если есть хотя бы один ключ
		if (this->m_p_key != 0x0)
		{
			counter++;

			// если более 2-х ключей
			if (this->m_p_next_elem != 0x0)
			{
				// временный элемент
				Stack <T>* temp_elem = this->m_p_next_elem;

				// пока указатель не равен нулю, увеличивать счетчик, переходя от элемента к элементу
				while (temp_elem != 0x0)
				{
					counter++;
					temp_elem = temp_elem->m_p_next_elem;
				};
			};
		};
		return counter;
	}

	// очистить стек
	template <typename T>
	void Stack<T>::Clear()
	{
		delete this->m_p_key;
		m_p_key = 0x0;

		delete this->m_p_next_elem;
		m_p_next_elem = 0x0;
	}
}

#endif /* _STACK_H_ */
