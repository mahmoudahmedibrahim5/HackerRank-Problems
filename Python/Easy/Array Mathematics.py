import numpy

n, m = list(map(int, input().split()))
a = []
b = []
for i in range(n):
    a.append(list(map(int, input().split())))
for i in range(n):
    b.append(list(map(int, input().split())))

A = numpy.array(a)
B = numpy.array(b)

print(A+B)
print(A-B)
print(A*B)
print(A//B)
print(A%B)
print(A**B)
