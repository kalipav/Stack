///////////////////////////
// �����:  ������� ����� //
// ������: 03.01.2019    //
///////////////////////////

#include "Stack.h" // ����� � ��������� �����
#include "Stack_info.h" // ������ ��� ��������� ������, �������������� ��������, ������ ���������� ����������
#include <iostream>

using namespace kpm;

/*
	������� ��� �������� ������ kpm::Stack
*/
int main() try
{
	// ���� �� ������������� ���������, ����������� - 1000 ����
	Stack <int, 1000> my_stack;

	// ���������� ��� ���������� �������
	char command;

	// ����������� ����
	for (;;)
	{
		// ���� �������
		std::cout << "Enter the command:/n";
		std::cout << "> ";
		std::cin >> command;

		// �������� �� ������
		switch (command)
		{
		case 'q': // ����� �� ���������                                    <-----------------------   ��������� 
			break; 
		default:
			throw Stack_info("����������� �������\n");              // < ------------------------ �������������
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