import numpy

def arrays(arr):
    # complete this function
    # use numpy.array
    arr.reverse()
    return numpy.array(list(map(float, arr)))
    

arr = input().strip().split(' ')
result = arrays(arr)
print(result)