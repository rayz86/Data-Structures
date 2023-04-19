#include<stdio.h>

//function declaration
void bubblesort(int [],int);

int main()
{
    int a[20],i,n;

    printf("enter size of array:");
    scanf("%d",&n);

    for(i=0;i<=n-1;i++)
    {
        printf("enter element at pos[%d]:",i);
        scanf("%d",&a[i]);
    }

    //function call
    bubblesort(a,n);
    
    //printing final array
    printf("\nsorted array:\n");
    for(i=0;i<=n-1;i++)
    {
        printf("[%d]=%d",i,a[i]);
    }

    return 0;
}

//function definitio 
void bubblesort(int a[],int n)
{
    int i,j,flag;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]<a[j])
            {
                flag=a[j];
                a[j]=a[i];
                a[i]=flag;
            }
        }
    }
}
