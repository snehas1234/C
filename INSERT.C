#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};

struct node*createnode(int data)
{
struct node*newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
return newnode;
}

void insertAtEnd(struct node**head,int data)
{
struct node*newnode=createnode(data);
if(*head==NULL)
{
*head=newnode;
}
else{
struct node*temp=*head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
}

void insertAtIndex(struct node**head,int data,int index)
{
struct node*temp=*head;
int i;
struct node*newnode=createnode(data);
if(index==0)
{
newnode->next=*head;
*head=newnode;
return;
}

for(i=0;i<index-1&&temp!=NULL;i++)
{
temp=temp->next;
}
if(temp==NULL)
{
printf("Index out of bounds\n");
}
else{
newnode->next=temp->next;
temp->next=newnode;
}
}

void display(struct node*head)
{
struct node*temp=head;
while(temp!=NULL)
{
printf("%d->",temp->data);
temp=temp->next;
}
printf("NULL\n");
}

int main()
{
struct node*head=NULL;
int n,i,value,index;
clrscr();
printf("Enter the no.of nodes: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter value for node %d: ",i+1);
scanf("%d",&value);
insertAtEnd(&head,value);
}
printf("linked list:\n");
display(head);
printf("enter the value to insert: ");
scanf("%d",&value);
printf("enter the index to insert at: ");
scanf("%d",&index);
insertAtIndex(&head,value,index);
printf("updated list: ");
display(head);
getch();
return 0;
}
