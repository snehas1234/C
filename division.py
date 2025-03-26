import numpy as np

row1=int(input("enter the number of rows of first matrix:"))
col1=int(input("enter the number of columns of first matrix:"))
row2=int(input("enter the number of rows of second matrix:"))
col2=int(input("enter the number of columns of second matrix:"))

matrix1=[]
matrix2=[]

print("enter the values of matrix1")
for i in range(row1):
    row_data= list(map(int, input(f"enter the values of row {i+1}: ").split()))
    matrix1.append(row_data)

print("enter the values of matrix2")
for i in range(row2):
    row_data= list(map(int, input(f"enter the values of row {i+1}: ").split()))
    matrix2.append(row_data)

a=np.array(matrix1)
b=np.array(matrix2)
print(f"the matrices that you have entered are \n{a} \n{b}")

if a.shape==b.shape:
    print(f"the matrix after division is \n{a/b}")
else:
    print("the matrix division is not possible")


