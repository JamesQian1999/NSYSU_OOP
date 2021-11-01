#include "stack.h"
#include <iostream>
Stack::Stack()
{
	top = NULL;
};

void Stack::push(int x)
{
	Node *temp = new Node;
	temp->data = x;
	temp->next = top;
	top = temp;
};

int Stack::pop()
{
	int x;
	Node *temp = top;
	x = top->data;
	top = top->next;
	delete temp;
	return x;
};










