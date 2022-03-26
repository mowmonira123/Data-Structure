#include<stdio.h>
#include<stdlib.h>
int main()
{
    struct Node
    {
        int x;
        struct Node *next;
    };

    struct Head
    {
        int count;
        struct Node *p;
    };

    struct Head *head;
    struct Node *node,*temp;
    head=(struct Head*)malloc(sizeof(struct Head));
    temp=(struct Node*)malloc(sizeof(struct Head));
    head->count=0;
    head->p=NULL;

    void insertfirst(int y)
    {
        node=(struct Node*)malloc(sizeof(struct Node));
        node->x=y;
        node->next=NULL;
        head->p=node;
        head->count++;
    }

    void insertlast(int y)
    {
        node=(struct Node*)malloc(sizeof(struct Node));
        node->x=y;
        temp=head->p;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=node;
        node->next=NULL;
        head->count++;
    }
    void print()
    {
        temp=head->p;
        while(temp != NULL)
        {
            printf("%d \n",temp->x);
            temp=temp->next;
        }
    }
    void search(int q)
    {
        int x;
        temp=head->p;
        while(temp != NULL)
        {
            if(temp->x==q)
            {
                printf("found\n");
                return;
            }

            temp=temp->next;
        }
         printf("not found\n");
    }


    int i,z;
    for( i=0; i<3; i++)
    {
        int y;
        scanf("%d",&y);
        if(i==0)
        {
            insertfirst(y);
        }
        else
        {
            insertlast(y);
        }
    }
    printf("%d \n", head->count);
    print();
    printf("enter search number");
    scanf("%d",&z);
    search(z);
    return 0;


}
