#include<stdio.h>
#include<conio.h>

void printfibonacci(int n)
{
int a=0,b=1,c,i;
printf("Fibonacci series: %d,%d",a,b);
for(i=3;i<=n;i++)
{
c=a+b;
printf(",%d",c);
a=b;
b=c;
}
printf("\n");
}

int main()
{
int n;
clrscr();
printf("Enter the no.of terms: ");
scanf("%d",&n);
printfibonacci(n);
getch();
return 0;
}