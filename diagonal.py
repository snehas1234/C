import numpy as np

rows=int(input("enter the number of rows:"))
matrix=[]
for i in range(rows):
    row_data= list(map(int, input(f"enter the values of row {i+1}: ").split()))
    matrix.append(row_data)
a=np.array(matrix)
print(f"the matrix created is \n{a}")

diagonal=np.diag(a)
print(f"the diagonal elements are \n{diagonal}")

vector=list(map(int, input("enter the vector: ").split()))
matrix=np.diag(vector)

print(f"the matrix created  is \n{matrix}")