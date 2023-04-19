#include<stdio.h>
void quick(int [], int);
void display(int [], int);
int main()
{
    int i,n,arr[20];

    printf("enter the no. of elements:");
    scanf("%d",&n);
    arr[n];
    for(i=0;i<=n-1;i++)
    {
        printf("enter element at pos[%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("before sorting\n");
    display(arr, n);
    quick(arr, n);
    printf("\nafter sorting\n");
    display(arr, n);
}

void quick(int a[],int n)
{
    int p, r, l, temp, i;
    l=p=a[0];
    r=n-1;

    for(i=0;i<=n-1;i++)
    {
        if(a[p]<a[r])
        {
            r--;
            break;
        }

        else if(a[p]>a[r])
        {
            temp=a[p];
            a[p]=a[r];
            a[r]=temp;
            break;
        }
        else if(a[p]>a[l])
        {
            l++;
            break;
        }
    }
}

void display(int arr[], int n)
{
    for(int i=0;i<=n-1;i++)
    {
        printf("%d\t",arr[i]);
    }
}




