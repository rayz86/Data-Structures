#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void insertion(struct node** top,int element)
{
    struct node *tmp;
    tmp=((struct node*)malloc(sizeof(struct node)));

    if(top==NULL)
    {
        printf("Overflow");
    }

    else
    tmp->data=element;
    tmp->link=*top;
    *top=tmp;
}
void display(struct node *top)
{
    struct node *p;
    if(top==NULL)
    {
        printf("Underflow");
    }
    else
    {
        p=top;
        printf("\nElements in List\n");
        while(p!=NULL)
        {
            printf("\t%d",p->data);
            p=p->link;
        }
    }
}

int main()
{
    struct node *top=NULL;
    int n,x,ele;
    while(1)
    {
        printf("\n1.Insertion 2.Deletion 3.Display 4.Exit\n");
        scanf("%d",&x);

        switch(x)
        {
            case 1:
            printf("enter element to be inserted:");
            scanf("%d",&ele);
            insertion(&top,ele);
            printf("the list after insertion\n");
            display(top);
            break;

            case 2:
            deletion(&top);
            printf("the list after deletion\n");
            display(top);
            break;

            case 3:
            display(top);
            break;

            case 4:
            exit(1);

            default:
            printf("INVALID INPUT");
        }
    }
    return 0;
}

