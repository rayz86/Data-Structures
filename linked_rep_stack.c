#include<stdio.h>
struct node *start=NULL;
struct node
{
    struct node *next;
    int data;
};

struct node* push(struct node *start,int element)
{
    struct node *tmp;
    tmp=(struct node *) malloc(sizeof (struct node));
    if(tmp==NULL)
    {
        printf("stack overflow");
        return;
    }
    tmp->data=element;
    tmp->next=start;
    start=tmp;
}

struct node* pop(struct node *start)
{
    struct node *tmp;
    int item;
    if(start==NULL)
    {
        printf("stack underflow");
        return;
    }
    tmp=start;
    item=tmp->data;
    start=start->next;
    free(tmp);
    return item;
}

void display(start)
{
    if(start==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        struct node* p=start;
        printf("____________________________________");
        while(p!=NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("____________________________________\n\n");
    }
}
void peek(struct node *start)
{
    if(start==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        struct node* p=start;
        while(p!=NULL)
        {
            p=p->next;
        }
        printf("\nthe top most element in the list is:",p->data);
    }
}

int main()
{
    int i,n,ele,flag;
    printf("\n\n1.Insert 2.Delete 3.Display 4.Peek 5.EXIT");
    scanf("%d",&n);
    while(1)
    {
        switch(n)
        {
        case 1:
            printf("enter element to be inserted:");
            scanf("%d",&ele);
            push(start, ele);
            break;
        case 2:
            flag=pop(start);
            printf("%d was deleted from the list", flag);
            break;
        case 3:
            display(start);
            break;
        case 4:
            peek(start);
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("INAVLID INPUT");
            break;
        }
    }
    return 0;
}


