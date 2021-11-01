#ifndef __STACK_H__
#define __STACK_H__

class Node
{
	public:
		int data;
		Node *next;
};

class Stack
{
	public:
		Node *top;
		Stack();
		void push(int x);
		int pop();

};

#endif
