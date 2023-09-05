import numpy

n, m = list(map(int, input().split()))

lst = []
for i in range(n):
    lst.append(list(map(float, input().split())))
arr = numpy.array(lst)

print(numpy.mean(arr, axis=1))
print(numpy.var(arr, axis=0))
print(round(numpy.std(arr), 11))
