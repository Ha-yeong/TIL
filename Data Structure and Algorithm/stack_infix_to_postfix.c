#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char c){
	top++;
	stack[top] = c;
}

char pop(){
	top--;
	return stack[top+1];
}

char peek(){
	return stack[top];
}

int priority(char c){		//�켱������ ������ִ� �Լ�
	switch(c){
	case '(': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
}

void infix_to_prefix(char *p, int len){
	int i;

	for (i = 0; i < len+1; i++){
		if (p[i] > 79 && p[i] < 90){		//������ ���
			printf("%c", p[i]);
		}
		else if (p[i] == '(')				//���� ��ȣ�� ������ ���ÿ� ����
			push(p[i]);
		else if (p[i] == ')'){				//������ ��ȣ�� ������ �Ǹ� ���� ��ȣ�� ������ ������ ��� �����ڸ� ����Ѵ�.
			while (peek() != '(')
				printf("%c", pop());
			pop();
		}
		else{								//���ÿ� �ִ� �����ڰ� ���� ó�� ���� �����ں��� �켱������ ���ų� ������,
											//�ϴ� ���ÿ� �ִ� �����ڵ��� ���� ����� ������ ó�� ���� �����ڸ� ���ÿ� �ִ´�.
			while(top != -1 && priority(peek()) >= priority(p[i])){
				printf("%c", pop());
			}
			push(p[i]);
		}
	}
	printf("%c", pop());
}

int main(void)
{
	char equation[50];

	printf("enter infix equation: ");
	scanf("%s", equation);

	infix_to_prefix(equation, strlen(equation));

	return 0;
}