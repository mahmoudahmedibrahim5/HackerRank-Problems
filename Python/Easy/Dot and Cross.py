import numpy as np

n = int(input())

A = np.array([input().split() for _ in range(n)], int)
B = np.array([input().split() for _ in range(n)], int)
Bt = np.transpose(B)

result = np.zeros((n, n), dtype = int)

for i in range(n):
    for j in range(n):
        result[i][j] = np.dot(A[i], Bt[j])

print(result)
