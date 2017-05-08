#include <stdio.h>
#include <stdlib.h>

int top, num;
int* ptr;

void create()
{
	int i;
	ptr = (int*)malloc(sizeof(int)*num);
	top = -1;
}

int is_empty()
{
	if (top == -1) return 0;	//empty
	else return 1;				//not empty
}

int is_full()
{
	if (top == num-1) return 0;	//full
	else return 1;				//not full
}

void push()
{
	if (is_full() == 1){
		int a;

		printf("push what? ");
		scanf("%d", &a);

		top++;
		ptr[top] = a;
	}
	else printf("error! stack is full.\n");
}

void pop()
{
	if (is_empty() == 1){
		printf("pop %d\n", ptr[top]);
		top--;
	}
	else printf("error! stack is empty.\n");
}

int main(void)
{
	char choice;
	
	printf("how many stack? ");
	scanf("%d", &num);

	create();

	while(1){
		printf("\nwhat do you want to do?\n  push: 's'\n  pop: 'p'\n  exit: 'x'\n  ");
		scanf("%s", &choice);

		switch(choice){
		case 's':
			push();
			break;
		case 'p':
			pop();
			break;
		case 'x':
			exit(0);
		default:
			printf("not on menu.\n");
		}
	}

	return 0;
}