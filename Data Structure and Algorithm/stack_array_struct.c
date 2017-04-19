#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num, top;
	int* stack;
} StackType;

void init(StackType* s, int num)
{
	s->top = -1;
	s->num = num;
	s->stack = (int*)malloc(sizeof(int)*num);
}

int is_empty(StackType* s)
{
	if (s->top == -1) return 0;	//empty
	else return 1;				//not empty
}

int is_full(StackType* s)
{
	if (s->top == s->num -1) return 0;	//full
	else return 1;						//not full
}

void push(StackType* s)
{
	if (is_full(s) == 1){
		int a;

		printf("push what? ");
		scanf("%d", &a);

		s->top += 1;
		s->stack[s->top] = a;
	}
	else printf("error! stack is full.\n");
}

void pop(StackType* s)
{
	if (is_empty(s) == 1){
		printf("pop %d\n", s->stack[s->top]);
		s->top -= 1;
	}
	else printf("error! stack is empty.\n");
}

int main(void)
{
	StackType aStack;
	StackType bStack;
	char choice;
	int num;
	
	printf("how many stack to aStack? ");
	scanf("%d", &num);
	init(&aStack, num);

	printf("how many stack to bStack? ");
	scanf("%d", &num);
	init(&bStack, num);

	while(1){
		printf("\nwhat do you want to do?\n  push to aStack: '1'\n  pop from aStack: '2'\n");
		printf("  push to bStack: '3'\n  pop from bStack: '4'\n  exit: 'x'\n");
		scanf("%s", &choice);
		 
		switch(choice){
		case '1':
			push(&aStack);
			break;
		case '2':
			pop(&aStack);
			break;
		case '3':
			push(&bStack);
			break;
		case '4':
			pop(&bStack);
			break;
		case 'x':
			exit(0);
		default:
			printf("not on menu.\n");
		}
	}

	return 0;
}