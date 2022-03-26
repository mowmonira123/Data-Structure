#include<stdio.h>
int main()
{
    struct Node
    {
        int data;
        struct Node *Next;
    };
    struct Head
    {
        int count;
        struct Node *p;
    };

    struct Head *head;
    struct Node *temp,*node,*temp1;
    head=(struct Head*)malloc(sizeof(struct Head));
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp1=(struct Node*)malloc(sizeof(struct Node));
    head->count=0;
    head->p=NULL;

    void InsertFirst(int n,int m)
    {
        node=(struct Node*)malloc(sizeof(struct Node));
        node->data=m;
        head->p=node;
        node->Next=NULL;
        head->count++;
    }

    void Insert(int n,int m)
    {
        temp=head->p;
        while(temp->data!=n)
        {
            temp=temp->Next;
        }
        node=(struct Node*)malloc(sizeof(struct Node));
        node->data=m;
        node->Next=temp->Next;
        temp->Next=node;
        head->count++;
    }


    void Print()
    {
        printf("\nData Table:\n");
        printf("=============\n");
        temp=head->p;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->Next;
        }
        printf("\n");
    }




    void Delete(int n)
    {
        if(head->p->data==n)
        {
            temp=head->p;
            head->p=temp->Next;
            free(temp);
            head->count--;
        }
        else

        {
            int flag=0;
            temp=head->p;
            while(temp!=NULL)
            {
                if(temp->Next->data==n)
                {
                    flag=1;
                    break;
                }
                temp=temp->Next;
            }
            if(flag==0)
            {
                printf("Data Not found\n\n");
            }
            else
            {
                temp1=temp->Next;
                temp->Next=temp1->Next;
                free(temp1);
                head->count--;
                printf("Data Deleted Successfully!!!\n\n");
            }

        }

    }


    int i;
    for(i=0; i<=3; i++)
    {
        int x,y;
        printf("Enter Position:");
        scanf("%d",&x);
        printf("Enter Data:");
        scanf("%d",&y);
        if((x-1>head->count))printf("Invalid Position\n");
        else
        {
            if(i==0)
            {
                InsertFirst(x,y);
            }
            else
            {
                Insert(x,y);
            }
            Print();
        }

    }
    for(i=0; i<3; i++)
    {
        int x;
        printf("Enter value want to delete:");
        scanf("%d",&x);
        Delete(x);
        Print();
    }
    return 0;
}
