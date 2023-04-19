#include <stdio.h>
int BinarySearch (int [], int, int, int);
int main()
{
    int s,x,i,a[20],pos,f=0,l=0;
    printf("enter the size of array:");
    scanf("%d",&s);

    for(i=0;i<s;i++)
    {
        printf("enter element at pos[%d]:",i);
        scanf("%d",&a[i]);
    }
    printf("enter the element to be searched:");
    scanf("%d",&x);


    pos=BinarySearch(a,l,s,x);
    if (pos==-1)
    {
        printf("%d was not found",x);
    }
    else
    {
        printf("%d was found at position:%d",x,pos);
    }
    return 0;
}
int BinarySearch(int n[],int low,int high,int val)
{
    int mid;
    if(high >= low)
    {
        mid = (low + high)/2;
        if(n[mid] == val)
        {
            return mid;
        }
        else if(n[mid] < val)
        {
            return BinarySearch(n,mid+1,high,val);
        }
        else
        {
            return BinarySearch(n,low,mid-1,val);
        }
    }
    return -1;
}
