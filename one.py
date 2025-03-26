import numpy as np

row=int(input("enter the number of rows:"))
col=int(input("enter the number of columns:"))
matrix=np.ones((row,col),dtype=int)
print(f"the matrix created is \n{matrix}")