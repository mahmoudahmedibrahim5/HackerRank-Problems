import numpy

n, m = list(map(int, input().split()))
inpArr = []
for i in range(n):
    inpArr.append(list(map(int, input().split())))
array = numpy.array(inpArr)
print(numpy.transpose(array))
print(array.flatten())
