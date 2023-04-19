#include<stdio.h>

int binary(int [],int,int,int *);

int main()
{
    int a[20],i,n,s,ans,*p;

    printf("enter size of array:");
    scanf("%d",&n);

    for(i=0;i<=n-1;i++)
    {
        printf("enter element at pos[%d]:",i);
        scanf("%d",&a[i]);
    }

    printf("enter element to be searched:");
    scanf("%d",&s);

    ans=binary(a,n,s,&p);

    if(ans==1)
    {
        printf("element %d found at pos:%d",s,p);
    }

    else printf("element not found");
    //printf("element %d fount at array position :%d",s,ans);

    return 0;
}

int binary(int arr[],int size,int item,int *p)
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
            p=arr[mid];
            return 1;
        }

        else
            return 0;
    }
}

