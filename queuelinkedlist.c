#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    struct queue *link;
};

struct queue *start = NULL;

struct queue* add_queue(struct queue *start, int elem)
{
    struct queue *tmp;
    tmp = (struct queue* )malloc(sizeof(struct queue));
    if(start == NULL)
    {
        tmp -> data = elem;
        tmp->link = NULL;
        start = tmp;
        return start;
    }
    else
    {
        struct queue *p;
        p = start;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        tmp -> data = elem;
        tmp->link = NULL;
        p->link = tmp;
        return start;
    }
}

struct queue* del_queue(struct queue* start)
{
    struct queue *tmp;
    tmp = (struct queue*)malloc(sizeof(struct queue));
    if(start == NULL)
    {
        printf("*****queue IS EMPTY*****");
    }
    else
    {
        tmp = start;
        start = start->link;
        free(tmp);
    }
    return start;
}

void display(struct queue *start)
{
    if(start == NULL)
    {
        printf("*****QUEUE IS EMPTY*****");
    }
    else
    {
        struct queue *p;
        p = start;
        printf("QUEUE: ");
        while(p!=NULL)
        {
            printf("%d ", p->data);
            p = p->link;
        }
    }
}
void peek(struct queue *start)
{
    struct queue *p;
    p=start;
    printf("TOP ELEMENT:%d", p->data);
}
int main()
{
    int OP;
    while(1)
    {
        printf("\n-----------------------------\n");
        printf("1.ADD AN ELEMENT\n2.DELETE AN ELEMENT\n3.DISPLAY \n4:PEEK \n5.EXIT\n\nOperation: ");
        scanf("%d", &OP);
        switch(OP)
        {
            case 1:
                {
                    int element;
                    printf("enter the element to enter: ");
                    scanf("%d", &element);
                    start = add_queue(start, element);
                }
                break;

            case 2:
                {
                    start = del_queue(start);
                }
                break;

            case 3:
                {
                    display(start);
                }
                break;

            case 4:
                peek(start);
            break;

            case 5:
                exit(1);
            default: printf("INVALID INPUT");
        }
    }

    return 0;
}


