import numpy



index = input().split(" ")
arr = []
for i in range(0, int(index[0]), 1):
    arr.append(list(map(int,input().split(" "))))

sum_array = numpy.sum(arr, axis = 0)
result = numpy.prod(sum_array)
print(result)
