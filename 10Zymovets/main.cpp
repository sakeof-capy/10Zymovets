#include "ArrayQueue.h"
#include "ListQueue.h"
#include "UnboundedQueue.h"
#include "PeekBackArrayQueue.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

//***********************************************************
//	��������� ���� ����������� ���� �� ��������� ����� 
//	�������. ���������� ��������� ������������ �����
//	�) �� ��� ������ (�������� �����)
//	�) �� ��� ������
//	�) �� ��� ������ (���������� �����) *** (������� �����)
//	�� � ���� ���������� ����������?
//	Developed by Ruslan Zymovets (SE, group 1) on April 30
//	Version 1.0
//***********************************************************


//Const iterators?

int main(void)
{

	


	PeekBackArrayQueue<2, int> pbaq;
	PeekBackArrayQueue<2, int> pbaq2;
	//pbaq = pbaq2;
	pbaq.put(2);
	cout << pbaq << endl;
	ArrayQueue<2, int> aq;
	auto itor = ArrayQueue<2, int>::Iterator(aq);
	auto itor2 = PeekBackArrayQueue<2, int>::Iterator(pbaq);
	//itor = itor2;
	try
	{
		aq.front();
	}
	catch(const ArrayQueue<2,int>::BadQueue& b)
	{
		b.print_diagnosis(cout);
	}

	/*UnboundedQueue<int> uq;
	for (int i = 0; i < 20; ++i)
	{
		cout << uq << endl;
		uq.put(i);
	}
	uq.pop();
	cout << uq << endl;
	uq.put(20);
	cout << uq << endl;
	for (int i = 0; i < 20; ++i)
	{
		uq.pop();
		cout << uq << endl;
	}*/
	/*ListQueue<int> q;
	cout << q << endl;
	q.put(10);
	cout << q << endl;
	q.put(20);
	cout << q << endl;
	q.pop();
	cout << q << endl;
	q.pop();
	cout << q << endl;
	q.put(10);
	cout << q << endl;
	q.put(20);
	cout << q << endl;
	q.pop();
	cout << q << endl;
	q.pop();
	cout << q << endl;*/

	/*ArrayQueue<20, int> aq;
	cout << aq << endl;
	aq.put(10);
	cout << aq << endl;
	aq.put(20);
	cout << aq << endl;
	aq.pop();
	cout << aq << endl;
	aq.pop();
	cout << aq << endl;
	aq.put(10);
	cout << aq << endl;
	aq.put(20);
	cout << aq << endl;
	aq.pop();
	cout << aq << endl;
	aq.pop();
	cout << aq << endl;
	cout << aq << endl;
	aq.put(1);
	aq.put(2);
	aq.put(3);
	aq.put(4);
	aq.pop();
	aq.pop();
	aq.put(5);
	
	cout << aq << endl;
	cout << q << endl;*/

	/*IQueue<int>* iq = new ListQueue<int>();
	iq->put(10);
	iq->put(20);
	iq->put(30);
	delete iq;*/

	/*PeekBackArrayQueue<5, int> pbaq;
	for (int i = 0; i < 4; ++i)
	{
		pbaq.put(i);
	}
	cout << pbaq[0] << endl;
	pbaq.pop();
	cout << pbaq[0] << endl;
	pbaq.put(10);
	cout << pbaq[3] << endl;*/
	return 0;
}