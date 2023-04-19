#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack *link;
};

struct stack *start=NULL;

struct stack* add_stack(struct stack *start, int elem)
{
    struct stack *tmp;
    tmp = (struct stack* )malloc(sizeof(struct stack));
    if(start == NULL)
    {
        tmp -> data = elem;
        tmp->link = NULL;
        start = tmp;
        return start;
    }
    else
    {
        struct stack *p;
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

struct stack* del_stack(struct stack* start)
{
    if(start == NULL)
    {
        printf("*****STACK IS EMPTY*****");
        return start;
    }
    else
    {
        struct stack *tmp, *p;
        tmp = (struct stack* )malloc(sizeof(struct stack));
        p = start;
        while(p->link->link!= NULL)
        {
            p= p->link;
        }
        tmp = p->link;
        free(tmp);
        p->link = NULL;
        return start;
    }
}

void display(struct stack *start)
{
    if(start == NULL)
    {
        printf("*****STACK IS EMPTY*****");
    }
    else
    {
        struct stack *p;
        p = start;
        printf("STACK: ");
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
                int elem;
                printf("\nenter the element to enter: ");
                scanf("%d", &elem);
                start = add_stack(start, elem);
            }
            break;

            case 2:
            {
                start = del_stack(start);
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
