#include<stdlib.h>
#include<stdio.h>

struct node
{
    int info;
    struct node *lchild, *rchild;
};

int isEmpty(struct node *p)
{
    if(p == NULL)
    {
        printf("No Nodes present in the tree!\n");
        return 1;
    }
    return 0;
}

void searching(struct node *root)
{
    if(!isEmpty(root))
    {
        int data;
        printf("Enter the element to search : ");
        scanf("%d", &data);
        struct node *tmp = root;
        while(tmp != NULL)
        {
            if(data == tmp -> info)
            {
                printf("\nElement is present in the tree\n");
                printf("\n");
                return;
            }
        }
        printf("\nElement not present in the tree!\n");
    }
    printf("\n");
}

struct node* createNode(int data)
{
    struct node *tmp = (struct node*) malloc(sizeof(struct node));
    tmp -> lchild = tmp -> rchild = NULL;
    tmp -> info = data;
    return tmp;
}

struct node* insertion(struct node *ptr, int data)
{
    if(ptr == NULL)
    {
        struct node *tmp = (struct node*) malloc(sizeof(struct node));
        tmp -> lchild = tmp -> rchild = NULL;
        tmp -> info = data;
        return tmp;
    }

    if(data < ptr -> info)
        ptr -> lchild = insertion(ptr -> lchild, data);
    else if(data > ptr -> info)
        ptr -> rchild = insertion(ptr -> rchild, data);
    else
        printf("\nDublicate Elements not allowed!\n");

    return ptr;
}

struct node *delCaseA(struct node *root, struct node *par, struct node *p)
{
    if(root == p)
        root = NULL;
    if(par -> lchild == p)
        par -> lchild = NULL;
    else
        par -> rchild = NULL;

    free(p);
    return root;
}
struct node *delCaseB(struct node *root, struct node *par, struct node *p)
{
    struct node *tmp;
    if(p -> lchild != NULL)
        tmp = p -> lchild;
    else
        tmp = p -> rchild;

    if(p == root)
        root = tmp;
    if(par -> lchild == p)
        par -> lchild = tmp;
    else
        par -> rchild = tmp;
    free(p);
    return root;
}
struct node *delCaseC(struct node *root, struct node *par, struct node *p)
{
    struct node *parsuc, *succ;
    parsuc = p;
    succ = p -> rchild;
    while(succ -> lchild != NULL)
    {
        parsuc = succ;
        succ = succ -> lchild;
    }
    p -> info = succ -> info;
    if(succ -> lchild == NULL && succ -> rchild == NULL)
        root = delCaseA(root, parsuc, succ);
    else
        root = delCaseB(root, parsuc, succ);

    return root;
}

struct node *deletion(struct node *root, int item)
{
    if(isEmpty(root))
        return NULL;
    struct node *par, *p;
    p = root;
    par = NULL;
    while(p != NULL)
    {
        if(p -> info == item)
            break;
        par = p;
        if(item < p -> info)
            p = p -> lchild;
        else
            p = p -> rchild;
    }
    if(p == NULL)
    {
        printf("\nItem not found!\n");
        return root;
    }
    if(p -> lchild == NULL && p -> rchild == NULL)
    {
        root = delCaseA(root, par, p);
    }
    else if(p -> lchild != NULL && p -> rchild != NULL)
    {
        root = delCaseC(root, par, p);
    }
    else if(p -> lchild != NULL || p -> rchild != NULL)
    {
        root = delCaseB(root, par, p);
    }
    printf("\n");

    return root;
}
struct node* inorder(struct node *p)
{
    if(p == NULL)
        return NULL;
    else
    {
        inorder(p -> lchild);
        printf("%d ", p -> info);
        inorder(p -> rchild);
    }
}
struct node* preorder(struct node *p)
{
    if(p == NULL)
        return NULL;
    else
    {
        printf("%d ", p -> info);
        preorder(p -> lchild);
        preorder(p -> rchild);
    }
}
struct node* postorder(struct node *p)
{
    if(p == NULL)
        return NULL;
   else
    {
        postorder(p -> lchild);
        postorder(p -> rchild);
        printf("%d ", p -> info);
    }
}

int main()
{
    struct node *root = NULL;
    int ch, data;
    do
    {
        printf("-------------------------------\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. In-Order Traversal\n");
        printf("5. Post-Order Traversal\n");
        printf("6. Searching\n");
        printf("7. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter the element : ");
                    scanf("%d", &data);
                    root = insertion(root, data);
                    break;
            case 2: printf("Enter the element to delete : ");
                    scanf("%d", &data);
                    root = deletion(root, data);
                    break;
            case 3: preorder(root);break;
            case 4: inorder(root);break;
            case 5: postorder(root);break;
            case 6: searching(root);break;
            default: break;
        }
        printf("\n");
    }while(ch != 7);

    return 0;
}
