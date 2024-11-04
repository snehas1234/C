#include<stdio.h>
#include<conio.h>
int binary(int arr[100],int size,int target)
{
int first=0,last=size-1,mid;
while(first<=last)
{
mid=(first+last)/2;
if(arr[mid]==target)
{
return mid;
}
else if(mid < target)
{
first=mid+1;
}
else
{
last=mid-1;
}
}
return -1;
}

int main()
{
int size,target,result,i,arr[100];
clrscr();
printf("Enter the size of the array; ");
scanf("%d",&size);
printf("Enter the sorted numbers: \n");
for(i=0;i<=size;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter the number to be searched:");
scanf("%d",&target);
result=binary(arr,size,target);
if(result!=-1)
{
printf("Value found at index %d",result);
}
else
{
printf("value not found");
}
getch();
return 0;
}
