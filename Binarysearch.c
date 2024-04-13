/*C program to perform Binary search*/
#include <stdio.h>
void binarysearch(int *,int ,int );
int main()
{
    int a[20],n,i,key;
    printf("Enter the list size:");
    scanf("%d",&n);
    printf("Enter the elements in the list:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the key:");
    scanf("%d",&key);
    binarysearch(a,n,key);
    return 0;
}
void binarysearch(int *a,int n,int key)
{
    int low,mid,high,count=0;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==a[mid])
        {
            printf("Key is found at index:%d",mid);
            count=1;
            break;
        }
        else if(key<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    if(count==0)
        printf("Search is unsuccesful");
}