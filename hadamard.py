import numpy as np

rows=int(input("enter the number of rows:"))
cols=int(input("enter the number of columns:"))

matrix1=[]
matrix2=[]

print("enter the values of matrix1")
for i in range(rows):
    row_data= list(map(int, input(f"enter the values of row {i+1}: ").split()))
    matrix1.append(row_data)

print("enter the values of matrix2")
for i in range(rows):
    row_data= list(map(int, input(f"enter the values of row {i+1}: ").split()))
    matrix2.append(row_data)

a=np.array(matrix1)
b=np.array(matrix2)

hadamard_product=a*b

print(f"the hadamard product of the matrices is \n{hadamard_product}")