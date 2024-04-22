#include<stdio.h>
#include<string.h>
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
	return stack[top--];
}
int isPalindrome(char str[])
{
	char item;
	int i,n;
	n=strlen(str);
	for(i=0;i<n/2;i++)
		push(str[i]);
	if(n%2==1)
		i=(n/2)+1;
	else
		i=n/2;
	while(str[i]!='\0')
	{
		item=pop();
		if(item!=str[i])
			return 0;
		i++;
	}
	return 1; 
}
int main()
{
	char str[MAX];
	printf("Enter a string:\n");
	scanf("%s",str);
	if(isPalindrome(str))
		printf("Given string is a Palindrome\n");
	else
		printf("Given string is not a Palindrome\n");
	return 0;
}
