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

int priority(char c){		//우선순위를 계산해주는 함수
	switch(c){
	case '(': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
}

void infix_to_prefix(char *p, int len){
	int i;

	for (i = 0; i < len+1; i++){
		if (p[i] > 79 && p[i] < 90){		//숫자인 경우
			printf("%c", p[i]);
		}
		else if (p[i] == '(')				//왼쪽 괄호는 무조건 스택에 삽입
			push(p[i]);
		else if (p[i] == ')'){				//오른쪽 괄호를 만나게 되면 왼쪽 괄호가 삭제될 때까지 모든 연산자를 출력한다.
			while (peek() != '(')
				printf("%c", pop());
			pop();
		}
		else{								//스택에 있는 연산자가 현재 처리 중인 연산자보다 우선순위가 높거나 같으면,
											//일단 스택에 있는 연산자들을 먼저 출력한 다음에 처리 중인 연산자를 스택에 넣는다.
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