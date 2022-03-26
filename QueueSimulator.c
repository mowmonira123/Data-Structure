/*****************************
Project Name:Queue Simulator
Group Members:
1. Md Tanbin Hosain Himel
    ID:2018-1-60-151
2. Joy Barai
    ID:2018-1-60-011
3. Kamarum Monira Mow
    ID:2018-1-60-016
*****************************/

#include<stdio.h>
#include<stdlib.h>

float AverageWaitTime,TotalWaitTime,AverageServiceTime,TotalServiceTime;
int Bool;
struct Node
{
    int ID,Hour,Minit,ArrivalTime,ServiceTime,WaitingTime;
    struct Node *next;
};

struct Time
{
    int HH,MM,minit;
};

struct Head
{
    int count;
    struct Node *front,*rear;
};

struct Head* Create_Queue()
{
    struct Head* head;
    head=(struct Head*)malloc(sizeof(struct Head));
    head->front=head->rear=NULL;
    head->count=0;

    return head;
}

void Enqueue(struct Head* head,int id,int Arrive,int Service,int wait)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->ID=id;
    node->ArrivalTime=Arrive;
    node->ServiceTime=Service;
    node->WaitingTime=wait;
    node->next=NULL;

    if(head->rear==NULL)
    {
        head->front=head->rear=node;
        head->count++;
        return;
    }

    head->rear->next=node;
    head->rear=node;
    head->count++;
}

void Dequeue(struct Head *head)
{
    if(head->front==NULL)
        return;

    struct Node *node=head->front;
    head->front=head->front->next;
    if(node->next==NULL)
        head->rear=NULL;
    free(node);
    head->count--;
}

int IsEmpty(struct Head* head)
{
    if(head->front==NULL)
        return 1;
    return 0;
}

void ConvertToHHMM(struct Time *time)
{
    time->HH=time->minit/60;
    time->MM=time->minit%60;
}

void PrintTable(struct Head *Queue,int n)
{
    printf("Printing Customer data...\n\n");
    for(int i=0; i<n; i++)
    {
        printf("#Customer ID: %.2d\n",Queue->front->ID);
        struct Time *t;
        t=(struct Time*)malloc(sizeof(struct Time));
        t->minit=Queue->front->ArrivalTime;
        ConvertToHHMM(t);
        printf("Arrival time: %.2d:%.2d\t",t->HH,t->MM);
        t->minit+=Queue->front->WaitingTime;
        ConvertToHHMM(t);
        printf("Served time: %.2d:%.2d\t",t->HH,t->MM);
        t->minit-=Queue->front->WaitingTime;
        printf("Service Time: %3d minutes\t",Queue->front->ServiceTime);
        printf("Waiting Time: %3d minutes\n\n",Queue->front->WaitingTime);
        ConvertToHHMM(t);

        Enqueue(Queue,Queue->front->ID,Queue->front->ArrivalTime,Queue->front->ServiceTime,Queue->front->WaitingTime);
        Dequeue(Queue);
    }

    printf("\Summary:\n");
    printf("Total People:          %.2d\n",Queue->count);
    printf("Total Waiting Time:    %2.2f minutes\n",TotalWaitTime);
    printf("Average Waiting Time:  %.2f minutes\n",AverageWaitTime);
    printf("Total Service Time:    %.2f minutes\n",TotalServiceTime);
    printf("Average Service Time:  %.2f minutes\n\n",AverageServiceTime);
}

void Display()
{
    printf("Menu:\n");
    printf("Please press...\n");
    printf("1: Enter Data.\n");
    printf("2: Calculate Data.\n");
    printf("3: Display Data.\n");
    printf("4: Instruction.\n");
    printf("0: Exit.\n\n");
    printf("Enter Key:");
}

struct Stack_Node
{
    int Data;
    struct Stack_Node *next;
};

struct Stack_Head
{
    int count;
    struct Stack_Node *top;
};

struct Stack_Head* Create_Stack()
{
    struct Stack_Head* head;
    head=(struct Stack_Head*)malloc(sizeof(struct Stack_Head));
    head->top=NULL;
    head->count=0;
    return head;
}

void InsertStack(struct Stack_Head* stack,int value)
{
    struct Stack_Node* s;
    s=(struct Stack_Node*)malloc(sizeof(struct Stack_Node));
    s->Data=value;
    s->next=stack->top;
    stack->top=s;
    stack->count++;
}

int IsEmptyStack(struct Stack_Head* stack)
{
    if(stack->count==0)
        return 1;
    return 0;
}

void PopStack(struct Stack_Head* stack)
{
    if(IsEmptyStack(stack)==1)
        return;
    struct Stack_Node* temp=(struct Stack_Node*)malloc(sizeof(struct Stack_Node));
    temp=stack->top;
    stack->top=temp->next;
    stack->count--;
    free(temp);
}

void Title()
{
    printf("************************************************************************************************************************\n");
    printf("                                                 \"Queue Simulator\"\n\n");
    printf("************************************************************************************************************************\n\n");
}
int main()
{
    struct Head* Queue=Create_Queue();
    struct Stack_Head* Stack=Create_Stack();
    int i,c,n,Current_Time,Waiting_Time,TotalPeople=0,id=1,Arrival_Time,Service_time,hour,minit,Key;
    int BOOL=0;
    system("COLOR F1");
    Title();
    Display();
    while(scanf("%d",&Key)==1)
    {
        if(Key==0)
        {
            system("cls");
            system("COLOR E1");
            Title();
            printf("Thanks for using our project...\n\n");
            printf("Press any key to exit...");
            getch();
            break;
        }
        if(Key==1)
        {
            system("cls");
            system("COLOR 71");
            Title();
            printf("Entering data...\n");
            printf("Total People:");
            scanf("%d",&n);

            for(i=0; i<n; i++)
            {
                printf("\nCustomer ID#%.2d\n",id);
                printf("Arrival Time(HH:MM):");
                scanf("%d:%d",&hour,&minit);
                printf("Service Time(minutes):");
                scanf("%d",&Service_time);
                Enqueue(Queue,id++,hour*60+minit,Service_time,0);
            }
            TotalPeople+=n;
            system("cls");
            BOOL=1;
            Title();
            printf("\nEntering data successful...\n");
            printf("Press any key to go to main menu...");
            getch();
            system("cls");
            system("COLOR F1");
            Title();
            Display();
        }
        else if(Key==2)
        {
            system("cls");
            system("COLOR 71");
            Title();
            if(IsEmpty(Queue)==0)
            {
                Current_Time=Queue->front->ArrivalTime;
                TotalServiceTime=0;
                for(i=0; i<TotalPeople; i++)
                {
                    Arrival_Time=Queue->front->ArrivalTime;
                    Service_time=Queue->front->ServiceTime;
                    int flag=0;
                    if(Current_Time>Arrival_Time)
                    {
                        Waiting_Time=(Current_Time-Arrival_Time);
                        InsertStack(Stack,Waiting_Time);
                        Enqueue(Queue,Queue->front->ID,Queue->front->ArrivalTime,Queue->front->ServiceTime,Waiting_Time);
                        flag=1;
                    }
                    Current_Time+=Service_time;
                    TotalServiceTime+=Service_time;
                    if(flag==0) Enqueue(Queue,Queue->front->ID,Queue->front->ArrivalTime,Queue->front->ServiceTime,0);
                    Dequeue(Queue);
                }

                c=0;
                while(IsEmptyStack(Stack)!=1)
                {
                    c+=Stack->top->Data;
                    PopStack(Stack);
                }
                TotalWaitTime=c;
                AverageWaitTime=(float)c/(float)Queue->count;
                AverageServiceTime=(float)TotalServiceTime/(float)Queue->count;
                BOOL=2;
                printf("\aData Calculation Complete...\n");
            }
            else
            {
                system("COLOR FC");
                printf("\aWarning:\nNo Customer data.Please entry customer data first.\n");
            }
            printf("\nPress any key to go to main menu...");
            getch();
            system("cls");
            system("COLOR F1");
            Title();
            Display();
        }
        else if(Key==3)
        {
            system("cls");
            system("COLOR E1");
            Title();
            if(BOOL==0)
            {
                system("COLOR FC");
                printf("\aWarning:\nNo Customer data.Please entry customer data first.\n");
            }
            else if(BOOL==1)
            {
                system("COLOR FC");
                printf("\aWarning:\nPlease calculate data first.Press 2 from the main menu to calculate data.\n");
            }
            else if(IsEmpty(Queue)==0)PrintTable(Queue,TotalPeople);

            printf("\nPress any key to go to main menu...");
            getch();
            system("cls");
            system("COLOR F1");
            Title();
            Display();
        }
        else if(Key==4)
        {
            system("cls");
            system("COLOR 71");
            Title();
            printf("\n\nInstruction:\n");
            printf("1.You have to enter data first.Without this you cannot calculate data and print data of the customers.\n");
            printf("2.After calculating data you will be able to print table of the customer.\n");
            printf("3.For Print Table please press 3 from the main menu.\n");
            printf("4.You have to maintain time sequence to get the correct results.\n\n");
            printf("\nPress any key to go to main menu...");
            getch();
            system("cls");
            system("COLOR F1");
            Title();
            Display();
        }
        else
        {
            system("cls");
            system("COLOR FC");
            Title();
            printf("\aWarning:\nYou entered wrong key.Please enter correct key.\n");
            printf("\nPress any key to go to main menu...");
            getch();
            system("cls");
            system("COLOR F1");
            Title();
            Display();
        }
    }
    return 0;
}
