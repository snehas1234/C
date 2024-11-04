#include<stdio.h>
#include<conio.h>
int getpalindrome(int num)
{
int rem,n,rev=0;
n=num;
while(n!=0)
{
rem=n%10;
rev=rev*10+rem;
n=n/10;
}
return rev;
}

int main()
{
int num,palindrome;
clrscr();
printf("Enter the number: ");
scanf("%d",&num);
palindrome=getpalindrome(num);
printf("Palindrome of %d is %d\n",num,palindrome);
getch();
return 0;
}
