import numpy

dimensions = list(map(int, input().split()))

print(numpy.zeros(dimensions, dtype = int))
print(numpy.ones(dimensions, dtype = int))
