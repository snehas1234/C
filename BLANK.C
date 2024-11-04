#include<stdio.h>
#include<conio.h>
void  main()
{
int s[20],i=-1,j;
char a[20];
clrscr();
printf("Enter the numbers: \n");
do{
i++;
fgets(a,10,stdin);
sscanf(a,"%d ",&s[i]);
}
while(a[0]!='\n');
printf("The numbers are: ");
for(j=0;j<i;j++)
{
printf("%d ",s[j]);
}
getch();
}
