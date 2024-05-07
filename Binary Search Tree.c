/*C program to perfrom operatins on Binary Search Tree*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *lchild,*rchild;
};

typedef struct node NODE;
NODE *root=NULL;

NODE * insert(NODE *,int);
void inorder(NODE *);
void preorder(NODE *);
void postorder(NODE *);
void search(NODE *,int);
int height(NODE *);
int count(NODE *);

int main()
{
	int item,ch;
	while(1)
	{
		printf("\nMENU\n");
		printf("1.Insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Search\n6.Heigth of Tree\n7.Count Nodes\n8.No.of Edges\n9.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element:");
					scanf("%d",&item);
					root=insert(root,item);
					break;
			case 2: inorder(root);
					break;
			case 3: preorder(root);
					break;
			case 4: postorder(root);
					break;
			case 5: printf("Enter a Key:");
					scanf("%d",&item);
					search(root,item);
					break;
			case 6: printf("Height of Tree:%d\n",height(root));
					break;
			case 7: printf("No.of Nodes=%d",count(root));
					break;
			case 8: printf("No.of Edges=%d",(count(root)-1));
					break;
			case 9: exit(0);
			default:printf("Invalid choice\n");
		}
	}
}

NODE* insert(NODE*root,int item)
{
	if(root==NULL)
	{
		root=(NODE*)malloc(sizeof(NODE));
		root->data=item;
		root->lchild=NULL;
		root->rchild=NULL;
	}
	else if(item >= root->data)
	{
		root->rchild=insert(root->rchild,item);
	}
	else
	{
		root->lchild=insert(root->lchild,item);
	}
	return root;
}

void inorder(NODE *root)
{
	if(root->lchild!=NULL)
		inorder(root->lchild);
	printf("%d ",root->data);
	if(root->rchild!=NULL)
		inorder(root->rchild);
}

void preorder(NODE *root)
{
	printf("%d ",root->data);
	if(root->lchild!=NULL)
		preorder(root->lchild);
	if(root->rchild!=NULL)
		preorder(root->rchild);
}

void postorder(NODE *root)
{
	if(root->lchild!=NULL)
		postorder(root->lchild);
	if(root->rchild!=NULL)
		postorder(root->rchild);
	printf("%d ",root->data);
}

void search(NODE *root,int key)
{
	if(root==NULL)
	{
		printf("Key is not found\n");
	}
	else if(key==root->data)
	{
		printf("Key is found\n");
	}
	else if(key < root->data)
	{
		search(root->lchild,key);
	}
	else
	{
		search(root->rchild,key);
	}
}

int height(NODE *root)
{
	int lsh,rsh;
	if(root==NULL)
		return 0;
	else
	{
		lsh=height(root->lchild);
		rsh=height(root->rchild);
		if(lsh>=rsh)
			return (lsh+1);
		else
			return (rsh+1);
	}
}

int count(NODE *root)
{
	int r;
	if(root==NULL)
		return 0;
	else
		return (count(root->lchild)+count(root->rchild)+1);
}
