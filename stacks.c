#include<stdio.h>

int top=-1,stack[20],max;
void push();
void pop();
void peek();
void display();

int main()
{
    int x;
    printf("enter max size of array:");
    scanf("%d",&max);
    stack[max];
    while(1)
    {
        printf("\n\n1:PUSH 2:POP 3:PEEK 4:EXIT\n");
        printf("enter a function:");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                exit(1);

            default:
                printf("wrong choice entered");
        }
    }

return 0;
}


void push()
{
    int element;
    if(top==max-1)
    {
        printf("Stack OVERFLOW");
    }
    else
    {
        top+=1;
        printf("enter the element to be pushed:");
        scanf("%d",&element);
        stack[top]=element;
        display();
    }
}

void pop()
{
    if(top==-1)
    {
       printf("STACK UNDERFLOW");
    }
    else
        top=top-1;
        display();
}

void peek()
{
    printf("top element:%d",stack[top]);
}

void display()
{
    printf("\nTHE STACK:");
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d\t",stack[i]);
    }
}
