/*C Program to perform Selection Sort */
#include<stdio.h>
void selectionsort (int *, int);
int main()
{
    int a[20], i, n;
    printf("Enter the size of list:");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    selectionsort(a,n);
    printf("Sorted list:\n");
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}
void selectionsort(int *a, int n)
{
    int i, j, temp, minpos;
    for(i=0; i<=(n-2); i++)
    {
        minpos = i;
        for(j=i+1; j<=(n-1); j++)
        {
            if( a[j]<a[minpos] )
                minpos=j;
        }
        temp = a[i];
        a[i] = a[minpos];
        a[minpos] = temp;
    }
}
