#include<stdio.h>

int main()
{
    int a[10],n,i,c=0,pos,s;
    printf("enter size of array:");
    scanf("%d",&n);

    for(i=0;i<=n-1;i++)
    {
        printf("enter element at pos[%d]:",i);
        scanf("%d",&a[i]);
    }

    printf("enter element to be searched:");
    scanf("%d",&s);

    for(i=0;i<=n;i++)
    {
        if(s==a[i])
        {
            pos=i;
            c=1;
        }
    }

    if(c==1)
    {
        printf("element %d found at pos :%d",s,pos);
    }

    else printf("element not found");

return 0;
}
