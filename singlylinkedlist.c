#include<stdio.h>
#include<stdlib.h>
struct node *start=NULL;
struct node
{
    int data;
    struct node *link;
};

//INSERTION
//insertion at the begenning
struct node*insertionatbeg(struct node *start,int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = start;
    start = temp;
    return start;
}

//insertion at the end
struct node* insertatend(struct node* start, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* p = start;
    while(p->link!=NULL)
        p = p->link;
    temp -> data = data;
    temp -> link = p -> link;
    p -> link = temp;
    return start;
}

//Insertion at a given position
struct node* insertatpos(struct node* start, int pos, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int i;
    //inserts at the beginning
    if(pos == 1)
    {
        temp -> data = data;
        temp -> link = start;
        start = temp;
        return start;
    }
    else{
        struct node* p = start;
        for(i=1; i<pos-1; i++)
            p = p->link;
        temp -> data = data;
        //inserting new node in between
        temp -> link = p -> link;
        p -> link = temp;
        return start;
    }
}

//Insertion before a given value
struct node* insertbeforenode(struct node* start, int item, int data)
{
    int i;
    struct node* temp, *p;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    p = start;
    while(p->link != NULL)
    {
        if(p->link->data == item)
        {
            temp -> link = p -> link;
            p -> link = temp;
            return start;
        }
        else
            p = p->link;
    }
    if(p->data != item)
        printf("Item not present in linked list\n");
    return start;
}

//Insertion after a given value
struct node* insertafternode(struct node* start, int item, int data)
{
    int i;
    struct node* temp, *p;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    p = start;
    while(p->link != NULL)
    {
        if(p->data == item)
        {
            temp -> link = p -> link;
            p -> link = temp;
        }
        else
            p = p->link;
    }
    if(p->data != item)
        printf("Item not present in linked list\n");
}

//DELETION
struct node* deletionatbeg(struct node* start)
{
    struct node *temp;
    temp = start;
    //List is empty
    if(start == NULL) {
        printf("Empty list\n");
    }
    else{
        printf("%d was deleted from the list\n",temp->data);
        start = start -> link;
        free(temp);
        return start;
    }
}
//Delete last node
struct node* deleteatlast(struct node* start)
{
    struct node *p;
    if(start == NULL){
        printf("List is empty\n");
    }
    else if(start -> link == NULL)
    {
        p = start;
        printf("%d was deleted from the list\n",p->data);
        free(p);
        start = NULL;
    }
    else
    {
        p = start;
        while(p->link->link!=NULL)
        {
            p = p -> link;
        }
        printf("%d was deleted\n",p->link->data);
        free(p->link);
        p -> link = NULL;
        return start;
    }
}

//Delete at a given position
struct node* deleteatpos(struct node* start, int pos)
{
    int i;
    struct node *p = start;
    struct node *temp;
    if(start == NULL)
        printf("List is empty\n");
    else if(pos == 1)
    {
        printf("%d was deleted from the list\n", start->data);
        start = NULL;
        free(p);
    }
    else
    {
        for(i=1; i<pos-1 && p!=NULL; i++)
            p = p -> link;
        temp = p;
        if(p==NULL)
        printf("\nNo of elements is less than the position");
        else
        {
            printf("%d is deleted\n",p->link->data);
            temp=p->link;
            p->link=temp->link;
            free(temp);
        }

    }
    return start;
}

void display(struct node *p)
{
    if(p==NULL)
    {
        printf("underflow or ");
    }
    while(p!=NULL)
    {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

//Counting elements in list
int count(struct node *start)
{
    int n=0;
    struct node *p = start;
    if(start == NULL)
        return 0;
    while(p!=NULL)
    {
        p = p -> link;
        n++;
    }
    return n;
}

//Reversal of list
struct node *reversal(struct node *start)
{
    struct node *prev, *p, *next;
    prev = NULL;
    p = start;
    while(p!=NULL)
    {
        next=p->link;
        p->link=prev;
        prev = p;
        p = next;
    }
    start = prev;
    return start;
}

//searching
void searching(struct node* start, int item)
{
    int pos=1;
    struct node *p=start;
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    while(p!=NULL)
    {
        if(p->data==item)
        {
            printf("%d was found at position %d", item, pos);
            break;
        }
        p=p->link;
        pos++;
    }
}

int main()
{
    struct node *start=NULL;
    int n,x,ele,val,c,c1,nodeval,pos,no;
    while(1)
    {
        printf("\n1.Insertion 2.Deletion 3.Traversal/Display 4.Count 5.Searching 6.Reversal 7.EXIT\n");
        scanf("%d",&x);

        switch(x)
        {
            case 1:
            printf("1.At the begenning 2.At the End 3.At a given Position 4.Before a given value 5.After a given value\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:
                printf("enter a value:");
                scanf("%d",&val);
                start=insertionatbeg(start,val);
                break;

                case 2:
                printf("enter a value:");
                scanf("%d",&val);
                start=insertatend(start,val);
                break;

                case 3:
                printf("enter a value:");
                scanf("%d",&val);
                printf("enter the position:");
                scanf("%d",&pos);
                start=insertatpos(start,pos,val);
                break;

                case 4:
                printf("enter value:");
                scanf("%d", &val);
                printf("enter node value:");
                scanf("%d", &nodeval);
                start=insertbeforenode(start,nodeval,val);
                break;

                case 5:
                printf("enter value:");
                scanf("%d", &val);
                printf("enter node value:");
                scanf("%d", &nodeval);
                start=insertafternode(start,nodeval,val);
                break;
            }
            break;

            case 2:
            printf("\n1.Delete at beginning 2.Delete at end 3.Delete at a given position\n");
            scanf("%d",&c1);
            switch(c1)
            {
                case 1:
                start=deletionatbeg(start);
                break;

                case 2:
                start=deleteatlast(start);
                break;

                case 3:
                printf("enter the position to delete:");
                scanf("%d",&pos);
                deleteatpos(start,pos);
                break;
            }
            break;

            case 3:
            display(start);
            break;

            case 4:
            no=count(start);
            printf("the number of elements present are:%d",no);
            break;

            case 5:
            printf("enter the element to be searched:");
            scanf("%d",&nodeval);
            searching(start,nodeval);
            break;

            case 6:
            start=reversal(start);
            break;

            case 7:
            exit(1);

            default:
            printf("INVALID INPUT");
        }
    }
    return 0;
}

