#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the flatlandSpaceStations function below.
def flatlandSpaceStations(n, c):
    c = sorted(c)
    maxDistance = c[0]
    
    for i in range(0, len(c)-1):
        index = math.floor((c[i] + c[i+1])/2)
        distance = (index - c[i])
        if (distance > maxDistance):
            maxDistance = distance
            
    distance = (n-1 - c[len(c)-1])
    if (distance > maxDistance):
        maxDistance = distance
        
    return maxDistance

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    c = list(map(int, input().rstrip().split()))

    result = flatlandSpaceStations(n, c)

    fptr.write(str(result) + '\n')

    fptr.close()
    