import numpy

n, m = list(map(int, input().split()))

lst = []
for i in range(n):
    lst.append(list(map(int, input().split())))

arr = numpy.array(lst)
minimum = numpy.min(arr, axis=1)

print(numpy.max(minimum))
