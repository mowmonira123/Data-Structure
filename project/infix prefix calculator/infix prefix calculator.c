#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE 100

struct node
{
    char x;
    struct node *next;
};

struct node *top;

//top = NULL;

void push(char c)
{
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));

    newnode -> x = c;
    newnode -> next = top;
    top = newnode;
}

char pop()
{
    char a;
    struct node *temp;
    temp = (struct node*) malloc(sizeof(struct node));

    a = top -> x;



    temp = top;
    top = top -> next;
    free(temp);

    return a;
}


int precedence(char symbol)
{
    if(symbol == '^')
    {
        return 3;
    }
    if(symbol == '*' || symbol == '/')
    {
        return 2;
    }
    if(symbol == '+' || symbol == '-')
    {
        return 1;
    }
    if(symbol == '(' || ')')
    {
        return 0;
    }
}


char* intopost(char str[])
{
    char *temp = (char *) malloc(sizeof(char) * strlen(str));
    char x;
    int i = 0, k = 0;




    while(str[i] != '\0')
    {
        if(isalnum(str[i]))
        {
            temp[k++] = str[i];
        }
        else if(str[i] == '(')
            push(str[i]);
        else if(str[i] == ')')
        {
            while((x = pop()) != '(')
                temp[k++] = x;
        }
        else
        {
            while(precedence(top -> x) >= precedence(str[i]))
                temp[k++] = pop();
            push(str[i]);
        }
        i++;
    }
    while(top != NULL)
    {
        temp[k++] = pop();
    }

    temp[k] = '\0';

    return temp;

}

char* intopre(char strn[])
{

    //top = NULL;
    char *temp = (char *) malloc(sizeof(char) * strlen(strn));
    char x;
    int i = 0, k = 0;
    //char temp[SIZE];



    while(strn[i] != '\0')
    {

        if(isalnum(strn[i]))
        {
            temp[k++] = strn[i];
        }
        else if(strn[i] == ')'){
            push(strn[i]);
        }
        else if(strn[i] == '(')
        {
            while((x = pop()) != ')')
                temp[k++] = x;
        }
        else
        {
            while(precedence(top -> x) >= precedence(strn[i]))
            {
                temp[k++] = pop();
            }
            push(strn[i]);
        }
        i++;
    }
    while(top != NULL)
    {
        temp[k++] = pop();
    }

    temp[k] = '\0';

    strrev(temp);

    //printf("%s", temp);

    return temp;

}


void postev(char str[])
{
    char x;
    int i = 0, num, n1,n2,n3;


    while(str[i] != '\0')
    {
        if(isdigit(str[i]))
        {
            num = str[i]- '0';
            push(num);
        }

        else
        {
            n1 = pop();
            n2 = pop();

            switch(str[i])
            {
                case '+':
                {
                   push(n3 = n1 + n2);
                   break;
                }
                case '-':
                {
                   push(n3 = n2 - n1);
                   break;
                }
                case '*':
                {
                   push(n3 = n1 * n2);
                   break;
                }
                case '/':
                {
                   push(n3 = n2 / n1);
                   break;
                }
            }
        }
        i++;
    }
    printf("\n\nThe result of the postfix expression is = %d",pop());
}

char* prev(char strn[])
{
    char reverse[SIZE];
    char x;
    int i = 0, num, n1,n2,n3;


    strrev(strn);
    strcpy(reverse,strn);

    while(reverse[i] != '\0')
    {
        if(isdigit(reverse[i]))
        {
            num = reverse[i]- '0';
            push(num);
        }

        else
        {
            n1 = pop();
            n2 = pop();

            switch(reverse[i])
            {
                case '+':
                {
                   push(n3 = n1 + n2);
                   break;
                }
                case '-':
                {
                   push(n3 = n2 - n1);
                   break;
                }
                case '*':
                {
                   push(n3 = n1 * n2);
                   break;
                }
                case '/':
                {
                   push(n3 = n2 / n1);
                   break;
                }
            }
        }
        i++;
    }
    printf("\n\nThe result of the prefix expression is : %d",pop());



}


main()
{
    char exp[SIZE];
    char reverse[SIZE];
    char temporary[SIZE];

    printf("enter expression :\n");
    scanf("%s",exp);

    char *result = intopost(exp);
    printf("\nThe postfix expression is :\n");
    printf("%s", result);

    postev(result);

    strrev(exp);
    strcpy(reverse,exp);
    char *Result = intopre(reverse);
    printf("\nThe prefix expression is :\n");
    printf("%s", Result);

    prev(Result);
}
