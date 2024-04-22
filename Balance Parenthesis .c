/*C progeam to check the Parenthesis is balanced dor not*/
#include<stdio.h>
#include<stdlib.h>
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
	if(top==-1)
	{
		printf("Not Balanced\n");
		exit(0);
	}
	return stack[top--];
}
int isMatch(char temp,char ch)
{
	if(temp=='(' && ch==')')
		return 1;
	else if(temp=='[' && ch==']')
		return 1;
	else if(temp=='{' && ch=='}')
		return 1;
	else
		return 0;
}
int main()
{
	char exp[MAX],ch,temp;
	int i;
	printf("Enter the expression:\n");
	scanf("%s",exp);
	for(i=0;exp[i]!='\0';i++)
	{
		ch=exp[i];
		if(ch=='('||ch=='['||ch=='{')
			push(ch);
		else
		{
			temp=pop();
			if(!isMatch(temp,ch))
			{
				printf("Not Balanced\n");
				exit(0);
			}
		}
	}
	if(top==-1)
		printf("Balanced\n");
	else
		printf("Not Balanced\n");
	return 0;
}
