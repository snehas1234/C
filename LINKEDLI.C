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

void append(struct node**head,int data)
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

void search(struct node*head,int key)
{
struct node*temp=head;
int position=1,found=0;
while(temp!=NULL)
{
if(temp->data==key)
{
printf("Node with value %d found at position %d.\n",key,position);
found=1;
break;
}
temp=temp->next;
position++;
}
if(!found)
{
printf("Node with value %d not found in the list.\n",key);
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
int i,n,value,searchvalue;
clrscr();
printf("Enter the no.of elements:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter element %d:",i+1);
scanf("%d",&value);
append(&head,value);
}
printf("linked list:");
display(head);
printf("Enter the element to be found: ");
scanf("%d",&searchvalue);
search(head,searchvalue);
getch();
return 0;
}
