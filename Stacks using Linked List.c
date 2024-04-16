/*C program to perform operations on Stacks using Linkedlist*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *head=NULL;
void insertfront(int);
void deletefront();
void display();
int main()
{
	int ch,item;
	while(1)
	{
		printf("\nMENU\n");
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the item:");
				scanf("%d",&item);
				insertfront(item);
				break;
			case 2:deletefront();
				break;
			case 3:display();
				break;
			case 4:exit(0);
			default:printf("Invalid choice");
		}
	}
}
void insertfront(int item)
{
	NODE *temp;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->data=item;
	temp->next=head;
	head=temp;
}
void deletefront()
{
	NODE *temp;
	if(head==NULL)
		printf("Stack Underflow");
	else
	{
		temp=head;
		head=head->next;
		printf("Deleted element:%d",temp->data);
		free(temp);
	}
}
void display()
{
	NODE *cur=head;
	if(head==NULL)
		printf("Stack is empty");
	else
	{
		printf("Stack contents:\n");
		while(cur!=NULL)
		{
			printf("%d ",cur->data);
			cur=cur->next;
		}
	}
}
