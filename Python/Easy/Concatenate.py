import numpy

n, m, p = list(map(int, input().split()))
x = []
y = []

for i in range(n):
    x.append(list(map(int, input().split())))

for i in range(m):
    y.append(list(map(int, input().split())))

x = numpy.array(x)
y = numpy.array(y)

print (numpy.concatenate((x, y), axis = 0))
