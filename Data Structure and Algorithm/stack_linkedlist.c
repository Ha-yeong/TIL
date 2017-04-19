#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int item;
	struct StackNode *link;
} StackNode;

typedef struct{
	StackNode *top;
} Stack;

void init(Stack* s)
{
	s->top = NULL;
}

int is_empty(Stack* s)
{
	if(s->top == NULL) return 0;	//empty
	else return 1;					//not empty
}

void push(Stack* s, int item)
{
	StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
	temp->item = item;
	temp->link = s->top;
	s->top = temp;
}

int pop(Stack* s)
{
	if (is_empty(s) == 1){
		int item;
		StackNode *temp = s->top;
		item = temp->item;
		s->top = temp->link;
		printf("pop %d\n", item);
		free(temp);
	}
	else printf("error! stack is empty.\n");
}

int main(void)
{
	Stack a;
	Stack b;
	char choice;
	int item;

	init(&a);
	init(&b);
	
	while(1){
		printf("\nwhat do you want to do?\n  push to aStack: '1'\n  pop from aStack: '2'\n");
		printf("  push to bStack: '3'\n  pop from bStack: '4'\n  exit: 'x'\n");
		scanf("%s", &choice);
		 
		switch(choice){
		case '1':
			printf("push what? ");
			scanf("%d", &item);
			push(&a,item);
			break;
		case '2':
			pop(&a);
			break;
		case '3':
			printf("push what? ");
			scanf("%d", &item);
			push(&b, item);
			break;
		case '4':
			pop(&b);
			break;
		case 'x':
			exit(0);
		default:
			printf("not on menu.\n");
		}
	}
	return 0;
}