#include<stdlib.h>
#include<math.h>
#include<string.h>
int pop();

int priority(char symbol);
int isEmpty();
void infix_to_prefix();
int check(char symbol);
void push(long int symbol);
char prefix_string[20], infix_string[20], postfix_string[20];
int top;
long int stack[20];
int main()
{
    int count, size;
    char temp;
    top = -1;
    printf("\nEnter an Expression in Infix format:\t");
    scanf("%[^\n]s", infix_string);
    infix_to_prefix();
    printf("\nExpression in Postfix Format: \t%s\n", postfix_string);
    size = strlen(postfix_string) - 1;
    strncpy(prefix_string, postfix_string, 20);
    for(count = 0; count < size; count++, size--)
    {
        temp = prefix_string[count];
        prefix_string[count] = prefix_string[size];
        prefix_string[size] = temp;
    }
    printf("\nExpression in Prefix Format: \t%s\n", prefix_string);
    return 0;
}
void infix_to_prefix()
{
    unsigned int count, temp = 0;
    char next;
    char symbol;
    for(count = 0; count < strlen(infix_string); count++)
    {
        symbol = infix_string[count];
        if(!check(symbol))
        {
            switch(symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next = pop()) != '(')
                {
                    postfix_string[temp++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while(!isEmpty() && priority(stack[top]) >= priority(symbol))
                    postfix_string[temp++] = pop();
                push(symbol);
                break;
            default:
                postfix_string[temp++] = symbol;
            }
        }
    }
    while(!isEmpty())
    {
        postfix_string[temp++] = pop();
    }
    postfix_string[temp] = '\0';
}
int priority(char symbol)
{
    switch(symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}
int check(char symbol)
{
    if(symbol == '\t' || symbol == ' ')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(long int symbol)
{
    if(top > 20)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    top = top + 1;
    stack[top] = symbol;
}
int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    return(stack[top--]);
}
