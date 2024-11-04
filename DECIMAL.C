#include<stdio.h>
#include<conio.h>
#include<math.h>
int binary(int n)
{
int decimal=0,i=0,rem;
while(n!=0)
{
rem=n%10;
n=n/10;
decimal=decimal+rem*pow(2,i);
i++;
}
return decimal;
}

int main()
{
int n,result;
clrscr();
printf("enter the binary number: ");
scanf("%d",&n);
result=binary(n);
printf("decimal equivalent: %d\n",result);
getch();
return 0;
}
