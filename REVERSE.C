#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
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

void reverse(struct node**head)
{
struct node*prev=NULL;
struct node*current=*head;
struct node*next=NULL;
while(current!=NULL)
{
next=current->next;
current->next=prev;
prev=current;
current=next;
}
*head=prev;
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
int n,value,i;
clrscr();
printf("Enter the number of nodes:");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("Enter the value for node %d :",i+1);
scanf("%d",&value);
insertAtEnd(&head,value);
}
printf("Original linked list\n");
display(head);
reverse(&head);
printf("Reversed linked list\n");
display(head);
getch();
return 0;
}
