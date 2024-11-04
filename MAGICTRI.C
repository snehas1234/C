#include<stdio.h>
#include<conio.h>
void printpascaltriangle(int n)
{
int line,i;
for(line=0;line<n;line++)
{
int value=1,i;
for(i=0;i<=line;i++)
{
printf("%d ",value);
value=value*(line-i)/(i+1);
}
printf("\n");
}
}

int main()
{
int n;
clrscr();
printf("enter the no.of rows:");
scanf("%d",&n);
printpascaltriangle(n);
getch();
return 0;
}
