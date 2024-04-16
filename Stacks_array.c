#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void push();
void pop();
void display();
int stack[MAX],top=-1;
int main()
{
	int ch,item;
	while(1)
	{
		printf("\nMENU");
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the item:");
					scanf("%d",&item);
					push(item);
					break;
			case 2:pop();
					break;
			case 3:display();
					break;
			case 4:exit(0);
			default :printf("Invalid choice\n");
		}
	}
}
void push(int item)
{
	if(top==MAX-1)
		printf("Stack Overflow\n");
	else
	{
		top++;
		stack[top]=item;
	}
}
void pop()
{
	if(top==-1)
		printf("\nStack Underflow");
	else
	{
		printf("Deleted element:%d",stack[top]);
		top--;
	}
}
void display()
{
	int i;
	if(top==-1)
		printf("\nStack is empty");
	else
	{
		printf("Contents of Stack:\n");
		for(i=top;i>-1;i--)
			printf("%d ",stack[i]);
	}
}
