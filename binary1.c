#include<stdio.h>

void binary(int [],int,int );

int main()
{
    int a[20],i,n,s;

    printf("enter size of array:");
    scanf("%d",&n);

    for(i=0;i<=n-1;i++)
    {
        printf("enter element at pos[%d]:",i);
        scanf("%d",&a[i]);
    }

    printf("enter element to be searched:");
    scanf("%d",&s);

    binary(a,n,s);
    return 0;
}

void binary(int arr[],int size,int item)
{
    int low=0,high=size-1,mid;
     while(low<=high)
    {
        mid=(low+high)/2;

        if(item>arr[mid])
        {
            low=mid+1;
        }

        else if(arr[mid]>item)
        {
            high=mid-1;
        }

        else if(item==arr[mid])
        {
            printf("element %d found at array position :%d",item,arr[mid]-1);
            break;
        }

        else
            printf("element not found");
    }
}



