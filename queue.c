#include<stdio.h>

int front=-1,queue[20],rear=-1,max;
void enqueue();
void dequeue();
void peek();
void display();
int isfull();
int isempty();

int main()
{
    int x;
    printf("enter max size of array:");
    scanf("%d",&max);
    queue[max];
    while(1)
    {
        printf("\n\n1:Enqueue 2:Dequeue 3:Peek 4:Display 5:EXIT\n");
        printf("enter a function:");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(1);

            default:
                printf("wrong choice entered");
        }
    }

return 0;
}


void enqueue()
{
    int element;
    if(isfull())
    {
        printf("QUEUE OVERFLOW");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        printf("enter the element to be pushed:");
        scanf("%d",&element);
        rear+=1;
        queue[rear]=element;
        display();
    }
}

void dequeue()
{
    if(isempty())
    {
       printf("QUEUE UNDERFLOW");
    }
    else
        front=front+1;
        display();
}

void peek()
{
    printf("front element:%d",queue[front]);
}

void display()
{
    printf("\nTHE QUEUE:");
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("%d\t",queue[i]);
    }
}

int isfull()
{
    if(rear==max-1)
    {
        return 1;
    }

    else
        return 0;
}

int isempty()
{
    if(front==-1 || front>rear)
    {
        return 1;
    }

    else
        return 0;
}

