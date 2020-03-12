import numpy as np

def matrixInv(A):    
    detA = np.linalg.det(A)
    if detA == 0 :
        return
    return np.linalg.inv(A)

A = np.matrix([[1, 2], [3, 4]])
print(A)
detA = matrixInv(A)
print(detA)