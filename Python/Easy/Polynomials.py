import numpy as np

coeff = np.array(input().split(), float)
x = int(input())

print(np.polyval(coeff, x))
