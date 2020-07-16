#include<iostream>
using namespace std;

class BstNode;
class Bst {
private:
	BstNode* root;
public:
	Bst() {
		root = 0;
	}
	BstNode* IterSearch(const int& x);
	void inorder();
	void inorder(BstNode* CurrentNode);
	bool Insert(const int& x);
	bool Delete(const int& x);
};

class BstNode {
	friend Bst;
private:
	BstNode* LeftChild;
	int data;
	BstNode* RightChild;
public:
	BstNode(int element = 0, BstNode* left = 0, BstNode* right = 0) {
		data = element;
		LeftChild = left;
		RightChild = right;
	}
};

BstNode* Bst::IterSearch(const int& x) {
	for (BstNode* t = root; t;) {
		if (x == t->data)
			return t;
		if (x < t->data)
			t = t->LeftChild;
		else
			t = t->RightChild;
	}
	return 0;
}

void Bst::inorder() {
	inorder(root);
}

void Bst::inorder(BstNode* CurrentNode) {
	if (CurrentNode) {
		inorder(CurrentNode->LeftChild);
		cout << CurrentNode->data << ' ';
		inorder(CurrentNode->RightChild);
	}
}

bool Bst::Insert(const int& x) {
	BstNode* p = root;
	BstNode* q = 0;

	while (p) {
		q = p;
		if (x == p->data) {
			cout << x << "가 이미 존재합니다." << endl;
			return false;
		}
		if (x < p->data)
			p = p->LeftChild;
		else
			p = p->RightChild;
	}
	p = new BstNode;
	p->LeftChild = p->RightChild = 0;
	p->data = x;

	if (!root)
		root = p;
	else if (x < q->data)
		q->LeftChild = p;
	else
		q->RightChild = p;
	return true;
}

bool Bst::Delete(const int& x) {
	BstNode* p = root;
	BstNode* q = 0;

	while (p) {
		if (x < p->data) {
			q = p;
			p = p->LeftChild;
		}
		else if (x > p->data) {
			q = p;
			p = p->RightChild;
		}
		else
			break;
	}

	if (!p) {
		cout << "삭제할 노드가 없습니다." << endl;
		return false;
	}
	if (p->LeftChild == 0 && p->RightChild == 0) {
		if (x < q->data) {
			q->LeftChild = 0;
			delete p;
		}
		else {
			q->RightChild = 0;
			delete p;
		}
	}
	else if (p->LeftChild == 0 || p->RightChild == 0) {
		if (p->LeftChild == 0) {
			if (x < q->data) {
				q->LeftChild = p->RightChild;
				delete p;
			}
			else {
				q->RightChild = p->RightChild;
				delete p;
			}
		}
		else {
			if (x < q->data) {
				q->LeftChild = p->LeftChild;
				delete p;
			}
			else {
				q->RightChild = p->LeftChild;
				delete p;
			}
		}
	}
	else {
		BstNode* r = p;
		q = p;
		p = p->RightChild;

		while (p->LeftChild) {
			q = p;
			p = p->LeftChild;
		}
		r->data = p->data;

		if (r == q) {
			r->RightChild = p->RightChild;
			delete p;
		}
		else if (p->RightChild) {
			q->LeftChild = p->RightChild;
			delete p;
		}
		else {
			q->LeftChild = 0;
			delete p;
		}
	}
	return true;
}

int main() {
	Bst bst;
	int menu, x, val;

	cout << "<<<<<<<<<<<<<<<<<<<<< 이진탐색트리 구현 >>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "(1) 삽입   (2) 삭제   (3) 탐색   (4) 중위우선순회   (0) 종료" << endl;

	while (1) {
		cout << "[메뉴 입력]" << endl;
		cin >> menu;

		switch (menu) {
		case 1:
			cout << "입력할 키 개수 : ";
			cin >> x;
			cout << "삽입할 키 입력 : ";
			for (int i = 0; i < x; i++) {
				cin >> val;
				bst.Insert(val);
			}
			break;
		case 2:
			cout << "삭제할 값 입력 : ";
			cin >> val;
			bst.Delete(val);
			break;
		case 3:
			cout << "탐색할 값 입력 : ";
			cin >> val;
			if (bst.IterSearch(val) == 0)
				cout << val << " => 탐색 실패" << endl;
			else
				cout << val << " => 탐색 성공" << endl;
			break;
		case 4:
			cout << "중위우선순회 : ";
			bst.inorder();
			cout << endl;
			break;
		case 0:
			break;
		}
		if (menu == 0)
			break;
	}
	return 0;
}