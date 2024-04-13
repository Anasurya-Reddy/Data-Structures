/*C Program that implements Bubble sort */
#include<stdio.h>
void bubblesort (int *, int);
int main()
{
    int a[20], i, n;
    printf("Enter the size of list:");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    bubblesort(a,n);
    printf("Sorted list:\n");
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}
void bubblesort(int *a, int n)
{
    int i, j, temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<(n-1-i); j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
