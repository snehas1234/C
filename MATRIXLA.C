#include<stdio.h>
#include<conio.h>
int findlargest(int rows,int cols,int matrix[5][5])
{
int i,j;
int largest=matrix[0][0];
for(i=0;i<rows;i++){
for(j=0;j<cols;j++){
if(matrix[i][j] > largest)
{
largest=matrix[i][j];
}
}
}
return largest;
}

int main()
{
int rows,cols,i,j;
int matrix[5][5];
int largest;
clrscr();
printf("enter the no.of rows: ");
scanf("%d",&rows);
printf("enter the no.of columns: ");
scanf("%d",&cols);
printf("enter the elements of the matrix:\n");
for(i=0;i<rows;i++){
for(j=0;j<cols;j++){
printf("element [%d][%d]:",i,j);
scanf("%d",&matrix[i][j]);
}
}
largest=findlargest(rows,cols,matrix);
printf("the largest number in the matrix is %d\n",largest);
getch();
return 0;
}

