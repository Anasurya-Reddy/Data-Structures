/*C program to perform operations on Queues using Linked List*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;

void insertlast(int);
void deletefront();
void display();

NODE *head=NULL;

int main()
{
	int ch,item;
	while(1)
	{
		printf("\nMENU\n");
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element:");
					scanf("%d",&item);
					insertlast(item);
					break;
			case 2: deletefront();
					break;
			case 3: display();
					break;
			case 4: exit(0);
			default :printf("Invalid Choice");
		}
	}
}

void insertlast(int item)
{
	NODE *cur,*temp;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->data=item;
	if(head==NULL)
		head=temp;
	else
	{
		cur=head;
		while(cur->next!=NULL)
			cur=cur->next;
		cur->next=temp;
	}
	temp->next=NULL;
}

void deletefront()
{
	NODE *temp;
	if(head==NULL)
		printf("Queue is empty\n");
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
		printf("Queue is Empty\n");
	else
	{
		while(cur!=NULL)
		{
			printf("%d ",cur->data);
			cur=cur->next;
		}
	}
}
