#include <stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50
void push (long int symbol);
long int pop();
void infix_topostfix();
long int eval_post();
int priority(char symbol);
int isempty();
int white_space(char symbol);
char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;

int main()
{
    long int value;
    top = -1;
    printf("\n\nenter the infix expression:");
    gets(infix);
    infix_topostfix();
    printf("\npostfix expression: %s\n\n", postfix);
    return 0;
}

void infix_topostfix()
{
    unsigned int i, p = 0;
    char next;
    char symbol;
    for(i=0; i< strlen(infix);i++)
    {
        symbol = infix[i];
        if(!white_space(symbol))
        {
            switch (symbol)
            {
                case '(':
                {push(symbol);}
                break;

                case ')':
                {
                    while((next = pop()) != '(')
                    {
                        postfix[p++] = next;
                    }
                }
                break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                {
                    while(!isempty() && priority(stack[top])>= priority(symbol))
                    {
                        postfix[p++] = pop();
                    }
                }
                push(symbol);
                break;

                default:
                {postfix[p++] = symbol;}
            }

        }
    }
    while(!isempty())
    {
        postfix[p++] = pop();
    }
    postfix[p] = '\0';
}

int priority(char symbol)
{
    switch(symbol)
    {
        case '(':
        {return 0;}

        case '+':

        case '-':
        {return 1;}

        case '*':
        case '/':

        case '%':
        {return 2;}

        case '^':
        {return 3;}

        default:
        {return 0;}
    }
}

void push (long int symbol)
{
    if(top>MAX)
    {
        printf("stack overflow\n");
        exit(1);
    }
    stack[++top] = symbol;
}

long int pop()
{
    if(isempty())
    {
        printf("stack underflow\n");
        exit(1);
    }
    return (stack[top--]);
}

int isempty()
{
    if(top ==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int white_space(char symbol)
{
    if(symbol == BLANK ||symbol == TAB)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
