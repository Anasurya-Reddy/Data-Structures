/*C program to perform operations on Simple Queues*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front=-1,rear=-1;

void insertlast(int );
void deletefront();
void display();

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
					break;
			default :printf("Invalid Choice\n");
		}
	}
}

void insertlast(int item)
{
	if(rear==MAX-1)
		printf("Queue is Full\n");
	else
	{
		rear++;
		queue[rear]=item;
		if(front=-1)
			front=0;
	}
}

void deletefront()
{
	if(front==-1)
		printf("Queue is Empty\n");
	else
	{
		printf("Deleted Element:%d\n",queue[front]);
		if(front==rear)
			front=rear=-1;
		else
			front++;	
	}
}

void display()
{
	int i;
	if(front==-1)
		printf("Queue is Empty\n");
	else
	{
		printf("Queue Contents:\n");
		for(i=front;i<=rear;i++)
			printf("%d ",queue[i]);
		printf("\n");
	}
}
