import numpy as np

rows=int(input("enter the number of rows:"))
matrix=[]
for i in range(rows):
    row_data= list(map(int, input(f"enter the values of row {i+1}: ").split()))
    matrix.append(row_data)
a=np.array(matrix)
print(f"the matrix created is \n{a}")

transpose=np.transpose(a)
print(f"the transpose of the give matrix is \n{transpose}")