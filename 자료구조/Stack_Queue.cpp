#include<iostream>
using namespace std;

class LinkedStack;            // ���ὺ�� ���漱��
class LinkedQueue;            // ����ť ���漱��
class ChainNode
{
	friend LinkedStack;       // LinkedStack freind ����
	friend LinkedQueue;       // LinkedQueue freind ����
private:
	int data;                 // data field
	ChainNode* link;          // link field
public:
	ChainNode(int element = 0, ChainNode* next = 0)   // ChainNode ������
	{
		data = element;
		link = next;
	}
};
class LinkedStack
{
private:
	ChainNode* top;
public:
	LinkedStack()                // LinkedStack ������
	{
		top = 0;
	}
	void Push(const int&);       // LinkedStack �����Լ�
	int* Pop(int&);              // LinkedStack �����Լ�
	void Print();                // LinkedStack ����Լ�
};
void LinkedStack::Push(const int& x)
{
	top = new ChainNode(x, top);     // �� ��带 top�� ����
}
int* LinkedStack::Pop(int& x)
{
	if (top == 0)                    // ������ ������� ���
		return 0;
	ChainNode* temp = top;
	x = top->data;                   // top ����� data field�� x�� ����
	top = top->link;                 // top�� ���� ���� �̵�
	delete temp;                     // ��� ����
	return &x;                       // x�� �ּ� ��ȯ
}
void LinkedStack::Print()
{
	ChainNode* p = top;
	if (top == 0)                    // ������ ������� ���
	{
		cout << "����ִ� ����" << endl;
		return;
	}
	else
	{
		cout << "����(LIFO��) : ";
		for (p; p->link; p = p->link)   // p�� top���� ���� ���� �̵�
		{
			cout << p->data << ' ';     // p�� data field ���
		}
		cout << p->data << endl;          // ������ data field ���
	}
}
class LinkedQueue
{
private:
	ChainNode* front;
	ChainNode* rear;
public:
	LinkedQueue()                 // LinkedQueue ������
	{
		front = rear = 0;
	}
	void Push(const int& e);      // LinkedQueue �����Լ�
	int* Pop(int&);               // LinkedQueue �����Լ�
	void Print();                 // LinkedQueue ����Լ�
};
void LinkedQueue::Push(const int& x)
{
	if (front == 0)                               // ť�� ������ ���
		front = rear = new ChainNode(x, 0);
	else
		rear = rear->link = new ChainNode(x, 0);  // ��� �����ϰ� rear ����
}
int* LinkedQueue::Pop(int& x)
{
	if (front == 0)             // ť�� ������� ���
		return 0;
	ChainNode* temp = front;    // ���ο� ��尡 �� �� ��带 ����Ű���� ����
	x = front->data;            // ������ ���� x�� ����
	front = front->link;        // front�� ���� ���� �̵�
	delete temp;                // �� �� ��� ����
	return &x;
}
void LinkedQueue::Print()
{
	ChainNode* p = front;
	if (rear == 0)              // ť�� ������� ���
	{
		cout << "����ִ� ť" << endl;
	}
	else {
		cout << "ť(FIFO��) : ";
		for (p; p->link; p = p->link)     // p�� front���� ���� ���� �̵�
		{
			cout << p->data << ' ';       // p�� data field ���
		}
		cout << p->data << endl;          // ������ data field ���
	}
}
int main()
{
	LinkedStack stack;          // LinkedStack ��ü ����
	LinkedQueue queue;          // LinkedQueue ��ü ����
	int menu, s, q;
	cout << "---------------�޴�---------------" << endl;
	cout << "1. ���ÿ� ����		2. ť�� ����" << endl;
	cout << "3. ���ÿ��� ����	4. ť���� ����" << endl;
	cout << "5. ���� ���� ����	6. ť ���� ����" << endl;
	cout << endl;

	while (1)
	{
		cout << "�޴��� ���� �Է� : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cin >> s;
			stack.Push(s);    // LinkedStack �����Լ� ȣ��
			break;
		case 2:
			cin >> q;
			queue.Push(q);    // LinkedQueue �����Լ� ȣ��
			break;
		case 3:
			stack.Pop(s);     // LinkedStack �����Լ� ȣ��
			break;
		case 4:
			queue.Pop(q);     // LinkedQueue �����Լ� ȣ��
			break;
		case 5:
			stack.Print();    // LinkedStack ����Լ� ȣ��
			break;
		case 6:
			queue.Print();    // LinkedQueue ����Լ� ȣ��
			break;
		}
	}
}