#include<stdio.h>
#define Size 60

int Top=-1, arr[Size],n;
void Push();
void Pop();
void Peek();
void Display();

int main()
{
	int choice;

    printf("enter size of stack: ");
    scanf("%d",&n);
    while (1)
    {
        printf("\nOperations performed by Stack");
        printf("\n1.Push \n2.Pop \n3.Peek\n4.Display\n5.Exit");
        printf("\n\nEnter the choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: Push();
                    break;
            case 2: Pop();
                    break;
            case 3: Peek();
                    break;
            case 4: Display();
                    break;
            case 5:
                    exit(1);
            default: printf("\nInvalid choice!!");
        }
    }

}

void Push()
{
	int x;

	if(Top==n-1)
	{
		printf("\nOverflow!!");
	}
	else
	{
		printf("\nEnter element to be inserted to the stack:");
		scanf("%d",&x);
		Top=Top+1;
		arr[Top]=x;
	}
}

void Pop()
{
	if(Top==-1)
	{
		printf("\nUnderflow!!");

	}
	else
	{
		printf("\nPopped element:  %d",arr[Top]);
		Top=Top-1;

	}
}
void Peek()
{
    if(Top == -1)
        printf("\n STACK IS EMPTY");

    else
        printf("top of stack: %d \n",arr[Top]);
}
void Display()
{

    int i;
	if(Top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("\nElements present in the stack: \n");
		for(i=Top;i>=0;--i)
			printf("%d\n",arr[i]);
	}
}

