#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'candies' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER_ARRAY arr
#

def candies(n, arr):
    # Write your code here
    candies = n
    kidsCandies = [1]*n
    inc = 0     #increment value
    
    # First we loop on the array in forward direction
    for i in range(0, n-1, 1):
        if (arr[i]>arr[i+1]) & (kidsCandies[i]<=kidsCandies[i+1]):
            inc = kidsCandies[i+1] - kidsCandies[i] + 1
            kidsCandies[i] += inc
            candies += inc
        elif (arr[i]<arr[i+1]) & (kidsCandies[i]>=kidsCandies[i+1]):
            inc = kidsCandies[i] - kidsCandies[i+1] + 1
            kidsCandies[i+1] += inc
            candies += inc
    
    # Second we loop on the array in backward direction
    for i in range(n-1, 0, -1):
        if (arr[i]>arr[i-1]) & (kidsCandies[i]<=kidsCandies[i-1]):
            inc = kidsCandies[i-1] - kidsCandies[i] + 1
            kidsCandies[i] += inc
            candies += inc
        elif (arr[i]<arr[i-1]) & (kidsCandies[i]>=kidsCandies[i-1]):
            inc = kidsCandies[i] - kidsCandies[i-1] + 1
            kidsCandies[i-1] += inc
            candies += inc
    
    return candies

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr_item = int(input().strip())
        arr.append(arr_item)

    result = candies(n, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
