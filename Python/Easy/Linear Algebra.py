import numpy as np

n = int(input())
A = np.array([input().split() for _ in range(n)], float)

print(round(np.linalg.det(A), 2))
