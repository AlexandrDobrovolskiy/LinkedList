#include "stdafx.h"
#include <iostream>

using namespace std;

class LinkedList {

	//The node of the stack
	struct Node {
		int data;
		Node *next;
	};

	// public members
public:

	// constructor
	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	// destructor
	~LinkedList() {
		Node *next = head;

		while (next) {
			Node *deleteMe = next;
			next = next->next;
			delete deleteMe; //please
		}
	}

	// adds the element to the front of the list
	bool pushFront(int data) {
		Node *newNode = new Node();
		newNode->data = data;

		if (tail == NULL) {
			tail = newNode;
		}

		newNode->next = head;
		head = newNode;

		return true;
	}

	int popFront() {
		if (head == NULL) // There might be an exeption I gues
			return 0;

		Node *newNode = head;
		int ret = newNode->data;

		head = head->next;
		delete newNode;
		return ret;
	}

	// adds the element to the end of the list
	bool pushBack(int data) {
		if (tail == NULL) {
			pushFront(data);
		}

		tail->next = new Node;
		tail->next->data = data;

		tail = tail->next;

		return true;
	}

	int popBack() {
		Node * temp = head;

		Node * deleteMe = tail;
		delete deleteMe;

		while (temp) {
			temp = temp->next;
		}

		tail = temp;

		return temp->data;
	}


	bool isEmpty() {
		return head == NULL;
	}

	// private members
private:
	Node * head;
	Node * tail;
};

int main()
{
	LinkedList * ll = new LinkedList();
	ll->pushFront(1);
	ll->pushFront(2);
	ll->pushFront(3);
	ll->pushFront(4);
	ll->pushBack(5);
	ll->pushBack(6);
	ll->pushBack(7);

	cout << ll->popBack() << endl;
	/*
	cout << ll->popFront() << endl;
	cout << ll->popFront() << endl;
	cout << ll->popFront() << endl;
	cout << ll->popFront() << endl;
	cout << ll->popFront() << endl;
	cout << ll->popFront() << endl;

	*/
	
	system("pause");
	return 0;
}


