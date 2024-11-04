#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX];
int top1=-1,top2=MAX;
void push1(int data)
{
if(top1<top2-1)
{
stack[++top1]=data;
printf("Pushed to stack1:%d\n",data);
}
else
{
printf("stack overflow!\n");
}
}
void push2(int data)
{
if(top1<top2-1)
{
stack[--top2]=data;
printf("Pushed to stack2:%d\n",data);
}
else
{
printf("stack overflow!\n");
}
}

void pop1()
{
if(top1>=0)
{
printf("Popped from stack1:%d\n",stack[top1--]);
}
else
{
printf("Stack1 underflow!\n");
}
}

void pop2()
{
if(top2<MAX)
{
printf("Popped from stack2:%d\n",stack[top2++]);
}
else{
printf("stack 2 underflow!\n");
}
}

void displaystack1()
{
int i;
if(top1>=0)
{
printf("Stack1: ");
for(i=0;i<=top1;i++)
{
printf("%d ",stack[i]);
}
printf("\n");
}
else{
printf("Stack1 is empty!\n");
}
}

void displaystack2()
{
int i;
if(top2<MAX)
{
printf("Stack2: ");
for(i=MAX-1;i>=top2;i--)
{
printf("%d ",stack[i]);
}
printf("\n");
}
else{
printf("Stack2 is empty!\n");
}
}

int main()
{
int choice,stackno,data;
clrscr();
printf("Stack operations:\n");
do{
printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nChoose an option: ");
scanf("%d",&choice);
switch(choice)
{

case 1:
printf("Enter the stack number(1 or 2):");
scanf("%d",&stackno);
printf("Enter the data to push: ");
scanf("%d",&data);
if(stackno==1)
{
push1(data);
}
else if(stackno==2)
{
push2(data);
}
else{
printf("Invalid stack number: ");
}
break;

case 2:
printf("enter stack number(1 or 2): ");
scanf("%d",&stackno);
if(stackno==1)
{
pop1();
}
else if(stackno==2)
{
pop2();
}
else{
printf("Invalid stack number!\n");
}
break;

case 3:
printf("Displaying both stacks\n");
displaystack1();
displaystack2();
break;

case 4:
exit(0);
break;

default:
printf("Invalid choice!\n");
}
}while(choice!=4);
return 0;
}
