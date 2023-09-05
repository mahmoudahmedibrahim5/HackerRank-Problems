import numpy as np

A = np.array([input().split()], int)
B = np.array([input().split()], int)

print(int(np.inner(A, B)))
print(np.outer(A, B))
