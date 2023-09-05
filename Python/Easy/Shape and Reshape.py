import numpy


if __name__ == "__main__":
    array = numpy.array(list(map(int, input().split())))
    print(numpy.reshape(array, (3, 3)))
    