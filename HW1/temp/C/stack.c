#include <stdlib.h>
#include "stack.h"

void push(struct stack* this, int x)
{
	struct node *stk = malloc(sizeof(struct node));
	stk->data = x;
	stk->next = this->sp;
	this->sp = stk;
}

int pop(struct stack* this)
{
	struct node *temp = this->sp;
	this->sp = this->sp->next;
	return temp->data;
}

struct stack* new_stack()
{
	struct stack* stk = malloc(sizeof(struct stack));
	stk->sp = NULL;
	return stk;
}

void delete_stack(struct stack* stk)
{
	free(stk);
}
