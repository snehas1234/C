#include<stdio.h>
#include<conio.h>
void reverse(int arr[100],int n)
{
int i,temp;
for(i=0;i<n/2;i++)
{
temp=arr[i];
arr[i]=arr[n-1-i];
arr[n-1-i]=temp;
}
}

int main()
{
int arr[100],i,size;
clrscr();
printf("Enter the size of the array:");
scanf("%d",&size);
printf("Enter the elements of the array: ");
for(i=0;i<size;i++)
{
scanf("%d",&arr[i]);
}
reverse(arr,size);
printf("Reversed array:\n");
for(i=0;i<size;i++)
{
printf("%d ",arr[i]);
}
getch();
return 0;
}