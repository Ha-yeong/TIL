#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

int is_empty(){
	if (top == -1) return 0;		//empty
	else return 1;					//not empty
}

void push(char a){
	top++;
	stack[top] = a;
}

char pop(){
	if (is_empty() == 1){
		return stack[top--];
	}
	else return 'x';  //if stack is empty, it means that parenthesis are not matching.
}

int check_matching(char *sentence){
	int i;
	char ch;

	for (i = 0; i < strlen(sentence); i++){
		if (sentence[i] == '(' || sentence[i] == '{' || sentence[i] == '[')
			push(sentence[i]);
		else if (sentence[i] == ')'){
			ch = pop();
			if (ch != '(') return -1;
		}
		else if (sentence[i] == '}'){
			ch = pop();
			if (ch != '{') return -1;
		}
		else if (sentence[i] == ']'){
			ch = pop();
			if (ch != '[') return -1;
		}
	}

	if (is_empty() == 1) return -1;
	else return 1;
}

int main(void)
{
	char sentence[50];

	printf("enter sentence(without blank): ");
	scanf("%s", sentence);

	if (check_matching(sentence) == 1) printf("successfully matching.\n");
	else printf("matching failed.\n");

	return 0;
}