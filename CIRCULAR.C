#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
int data;
struct node*next;
};

struct circularqueue{
struct node*front;
struct node*rear;
};

struct node*createnode(int data)
{
struct node*newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
return newnode;
}


void initializequeue(struct circularqueue*queue)
{
queue->front=NULL;
queue->rear=NULL;
}

int isempty(struct circularqueue*queue)
{
return(queue->front==NULL);
}

void enqueue(struct circularqueue*queue,int data)
{
struct node*newnode=createnode(data);
if(isempty(queue))
{
queue->front=newnode;
queue->rear=newnode;
newnode->next=newnode;
}
else
{
newnode->next=queue->front;
queue->rear->next=newnode;
queue->rear=newnode;
}
printf("Enqueued %d\n",data);
}

int dequeue(struct circularqueue*queue)
{
struct node*temp=queue->front;
int data;
if(isempty(queue))
{
printf("Queue is empty!\n");
return -1;
}
if(queue->front==queue->rear)
{
data=queue->front->data;
queue->front=NULL;
queue->rear=NULL;
}
else
{
data=queue->front->data;
queue->front=queue->front->next;
queue->rear->next=queue->front;
}
free(temp);
printf("Dequeued %d\n",data);
return data;
}

void display(struct circularqueue*queue)
{
struct node*temp=queue->front;
int data;
if(isempty(queue))
{
printf("Queue is empty!");
return;
}
printf("Queue: ");
do{
printf("%d->",temp->data);
temp=temp->next;
}while(temp!=queue->front);
printf("(back to front)\n");
}


int main()
{
struct circularqueue queue;
int choice,value;
clrscr();
initializequeue(&queue);
do
{
printf("\nCircular queue operations:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);

switch(choice)
{
case 1:

printf("Enter value to enqueue: ");
scanf("%d",&value);
enqueue(&queue,value);
break;

case 2:
dequeue(&queue);
break;

case 3:
display(&queue);
break;

case 4:
printf("exiting.\n");
exit(0);

default:
printf("Invalid choice.please enter a number between 1 and 4.\n");
}
}while(choice!=4);
getch();
return 0;
}


