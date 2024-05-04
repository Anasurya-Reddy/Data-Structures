#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int dequeue[MAX];
int front=-1,rear=-1;

void insertfront(int );
void insertrear(int );
void deletefront();
void deleterear();
void display();

int main()
{
	int ch,item;
	while(1)
	{
		printf("\n----------MENU-------------\n");
		printf("1.Insert Front\n2.Insert Rear\n3.Delete Frront\n4.Delete Rear\n5.Display\n6.Exit\n");
		printf("Enter your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element:");
					scanf("%d",&item);
					insertfront(item);
					break;
			case 2: printf("Enter the element:");
					scanf("%d",&item);
					insertrear(item);
					break;
			case 3: deletefront();
					break;
			case 4: deleterear();
					break;
			case 5: display();
					break;
			case 6: exit(0);
					break;
			default:printf("Invalid Input\n");
		}
	}
}

void insertfront(int item)
{
	if((rear+1)%MAX==front)
		printf("Dequeue is Full\n");
	else if(front==-1)
	{
		front=rear=0;
		dequeue[front]=item;
	}
	else if(front==0)
	{
		front=MAX-1;
		dequeue[front]=item;
	}
	else
	{
		front--;
		dequeue[front]=item;
	}
}

void insertrear(int item)
{
	if((rear+1)%MAX==front)
		printf("Dequeue is Full\n");
	else if(rear==-1)
	{
		front=rear=0;
		dequeue[rear]=item;
	}
	else 
	{
		rear=(rear+1)%MAX;
		dequeue[rear]=item;
	}
}

void deletefront()
{
	if(front==-1)
		printf("Dequeue is Empty\n");
	else if(front==rear)
	{
		printf("Deleted Element:%d",dequeue[front]);
		front=rear=-1;
	}
	else
	{
		printf("Deleted Element:%d",dequeue[front]);
		front=(front+1)%MAX;
	}
}

void deleterear()
{
	if(front==-1)
		printf("Dequeue is Empty\n");
	else if(front==rear)
	{
		printf("Deleted Element:%d",dequeue[front]);
		front=rear=-1;
	}
	else
	{
		printf("Deleted Element:%d",dequeue[rear]);
		rear=(rear-1)%MAX;
	}
}

void display()
{
	int i;
	if(front==-1)
		printf("Dequeue is empty\n");
	else
	{
		for(i=front;i!=rear;i=(i+1)%MAX)
			printf("%d ",dequeue[i]);
		printf("%d \n",dequeue[rear]);
	}
}
