#include <iostream>
using namespace std;

class Node {
	friend class Link;
private:
	int data;
	char name;
	Node *next;

public:
	Node();
	Node(char name, int data);
	~Node() {};
};

class Link {
private:
	Node *current = new Node();
	Node *head = new Node();
	Node *tail = new Node();

public:
	Link();
	void Gethead();
	void link_Node(char name, int data);
	void print();
	~Link() {};
};

Node::Node() {
	this->data = 0;
	this->name = 0;
	this->next = nullptr;
}

Node::Node(char name, int data) {
	this->data = data;
	this->name = name;
	this->next = nullptr;
}

Link::Link() {
	this->head = new Node();
	this->tail = new Node();
	this->current = head;
}

void Link::Gethead() {
	if(head->next == nullptr) {
		head->next = tail;
	}
}

void Link::link_Node(char name, int data) {
	Node *temp = new Node();
	Node *nextN = new Node(name, data);
	temp->next = current->next;
	current->next = nextN;
	nextN->next = temp->next;
	delete temp;
}

void Link::print() {
	current = head->next;
	while(current->next != nullptr) {
		cout << "name is : " << current->name << " data : " << current->data << endl;
		current = current->next;
	}
}

char name_list[20];

void make_name() {
	int index = 1;
	for(char x = 'a'; x < 'k'; x ++) {
		name_list[index] = x;
		index += 1;
	}
}

