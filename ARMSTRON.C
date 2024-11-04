#include<stdio.h>
#include<conio.h>
#include<math.h>
int isarmstrong(int num)
{
int rem,n,result=0;
n=num;
while(n!=0)
{
rem=n%10;
result=result+(rem*rem*rem);
n=n/10;
}
return result;
}

int main()
{
int num;
clrscr();
printf("Enter a number: ");
scanf("%d",&num);
if(isarmstrong(num)==num)
{
printf("%d is an armstrong number.\n",num);
}
else{
printf("%d is not an armstrong number.\n",num);
}
getch();
return 0;
}
