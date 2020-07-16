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
			cout << x << "�� �̹� �����մϴ�." << endl;
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
		cout << "������ ��尡 �����ϴ�." << endl;
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

	cout << "<<<<<<<<<<<<<<<<<<<<< ����Ž��Ʈ�� ���� >>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "(1) ����   (2) ����   (3) Ž��   (4) �����켱��ȸ   (0) ����" << endl;

	while (1) {
		cout << "[�޴� �Է�]" << endl;
		cin >> menu;

		switch (menu) {
		case 1:
			cout << "�Է��� Ű ���� : ";
			cin >> x;
			cout << "������ Ű �Է� : ";
			for (int i = 0; i < x; i++) {
				cin >> val;
				bst.Insert(val);
			}
			break;
		case 2:
			cout << "������ �� �Է� : ";
			cin >> val;
			bst.Delete(val);
			break;
		case 3:
			cout << "Ž���� �� �Է� : ";
			cin >> val;
			if (bst.IterSearch(val) == 0)
				cout << val << " => Ž�� ����" << endl;
			else
				cout << val << " => Ž�� ����" << endl;
			break;
		case 4:
			cout << "�����켱��ȸ : ";
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