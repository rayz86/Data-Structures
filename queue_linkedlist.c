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
int main()
{
    int OP;
    do
    {
        printf("\n-----------------------------\n");
        printf("1.ADD AN ELEMENT\n2.DELETE AN ELEMENT\n3.DISPLAY\n0.EXIT\n\nOperation: ");
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
        }
    }while(OP!=0);
    return 0;
}

