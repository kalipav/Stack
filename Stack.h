///////////////////////////
// �����:  ������� ����� //
// ������: 03.01.2019    //
///////////////////////////

#ifndef _STACK_H_
#define _STACK_H_

// ������������ ����
namespace kpm
{
	/* 
		#####   ����� "����"   #####
		* ���������� �� ����������� ������
		* T1 - ��� �����
		* unsigned int - ������������ ������ ����� � ������
	*/
	template <typename T1, unsigned int buffer>
	class Stack
	{
	private:
		// ��������� �������� �����
		struct stack_elem
		{
			// ����
			T1 key;

			// ��������� �� ��������� ������� �����
			Stack* next_elem;
		} m_stack_elem;

	public:
		// ����������� �������� �����
		Stack();

		// ���������� �������� �����
		~Stack();


	};

	template <typename T1, unsigned int buffer>
	Stack<T1, unsigned int>::Stack()
	{

	}


}

#endif /* _STACK_H_ */