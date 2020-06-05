#include<iostream>
using namespace std;

class LinkedStack;            // 연결스택 전방선언
class LinkedQueue;            // 연결큐 전방선언
class ChainNode
{
	friend LinkedStack;       // LinkedStack freind 지정
	friend LinkedQueue;       // LinkedQueue freind 지정
private:
	int data;                 // data field
	ChainNode* link;          // link field
public:
	ChainNode(int element = 0, ChainNode* next = 0)   // ChainNode 생성자
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
	LinkedStack()                // LinkedStack 생성자
	{
		top = 0;
	}
	void Push(const int&);       // LinkedStack 삽입함수
	int* Pop(int&);              // LinkedStack 삭제함수
	void Print();                // LinkedStack 출력함수
};
void LinkedStack::Push(const int& x)
{
	top = new ChainNode(x, top);     // 새 노드를 top에 저장
}
int* LinkedStack::Pop(int& x)
{
	if (top == 0)                    // 스택이 비어있을 경우
		return 0;
	ChainNode* temp = top;
	x = top->data;                   // top 노드의 data field를 x에 저장
	top = top->link;                 // top을 다음 노드로 이동
	delete temp;                     // 노드 삭제
	return &x;                       // x의 주소 반환
}
void LinkedStack::Print()
{
	ChainNode* p = top;
	if (top == 0)                    // 스택이 비어있을 경우
	{
		cout << "비어있는 스택" << endl;
		return;
	}
	else
	{
		cout << "스택(LIFO순) : ";
		for (p; p->link; p = p->link)   // p가 top부터 다음 노드로 이동
		{
			cout << p->data << ' ';     // p의 data field 출력
		}
		cout << p->data << endl;          // 마지막 data field 출력
	}
}
class LinkedQueue
{
private:
	ChainNode* front;
	ChainNode* rear;
public:
	LinkedQueue()                 // LinkedQueue 생성자
	{
		front = rear = 0;
	}
	void Push(const int& e);      // LinkedQueue 삽입함수
	int* Pop(int&);               // LinkedQueue 삭제함수
	void Print();                 // LinkedQueue 출력함수
};
void LinkedQueue::Push(const int& x)
{
	if (front == 0)                               // 큐가 비어었을 경우
		front = rear = new ChainNode(x, 0);
	else
		rear = rear->link = new ChainNode(x, 0);  // 노드 삽입하고 rear 수정
}
int* LinkedQueue::Pop(int& x)
{
	if (front == 0)             // 큐가 비어있을 경우
		return 0;
	ChainNode* temp = front;    // 새로운 노드가 맨 앞 노드를 가리키도록 설정
	x = front->data;            // 삭제할 값을 x에 저장
	front = front->link;        // front를 다음 노드로 이동
	delete temp;                // 맨 앞 노드 삭제
	return &x;
}
void LinkedQueue::Print()
{
	ChainNode* p = front;
	if (rear == 0)              // 큐가 비어있을 경우
	{
		cout << "비어있는 큐" << endl;
	}
	else {
		cout << "큐(FIFO순) : ";
		for (p; p->link; p = p->link)     // p가 front부터 다음 노드로 이동
		{
			cout << p->data << ' ';       // p의 data field 출력
		}
		cout << p->data << endl;          // 마지막 data field 출력
	}
}
int main()
{
	LinkedStack stack;          // LinkedStack 객체 생성
	LinkedQueue queue;          // LinkedQueue 객체 생성
	int menu, s, q;
	cout << "---------------메뉴---------------" << endl;
	cout << "1. 스택에 삽입		2. 큐에 삽입" << endl;
	cout << "3. 스택에서 삭제	4. 큐에서 삭제" << endl;
	cout << "5. 스택 내용 보기	6. 큐 내용 보기" << endl;
	cout << endl;

	while (1)
	{
		cout << "메뉴와 숫자 입력 : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cin >> s;
			stack.Push(s);    // LinkedStack 삽입함수 호출
			break;
		case 2:
			cin >> q;
			queue.Push(q);    // LinkedQueue 삽입함수 호출
			break;
		case 3:
			stack.Pop(s);     // LinkedStack 삭제함수 호출
			break;
		case 4:
			queue.Pop(q);     // LinkedQueue 삭제함수 호출
			break;
		case 5:
			stack.Print();    // LinkedStack 출력함수 호출
			break;
		case 6:
			queue.Print();    // LinkedQueue 출력함수 호출
			break;
		}
	}
}