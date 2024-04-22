/*C programe to convert Infix expression to Postfix Expression*/
#include<stdio.h>
#include<ctype.h>
#define MAX 20
char stack[MAX];
int top=-1;
void push(char item)
{
	top++;
	stack[top]=item;
}
char pop()
{
	char ch;
	if(top==-1)
		return -1;
	else
	{
		ch=stack[top];
		top--;
		return ch;
	}
}
int priority(char ch)
{
	if(ch=='+' || ch=='-')
		return 1;
	if(ch=='*' || ch=='/' || ch=='%')
		return 2;
	return 0;
}
int main()
{
	char infix[50],ch,x;
	int i;
	printf("Enter the Infix Expression\n");
	scanf("%s",infix);
	for(i=0;infix[i]!='\0';i++)
	{
		ch=infix[i];
		if(isalnum(ch))
			printf("%c ",ch);
		else if(ch=='(')
			push(ch);
		else if(ch==')')
			while((x=pop())!='(')
				printf("%c ",x);
		else
		{
			while(priority(stack[top])>=priority(ch))
				printf("%c ",pop());
			push(ch);
		}
	}
	while(top!=-1)
		printf("%c ",pop());
	printf("\n");
	return 0;
}	
