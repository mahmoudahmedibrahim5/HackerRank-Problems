#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'countingValleys' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER steps
#  2. STRING path
#

def countingValleys(steps, path):
    # Write your code here
    level = 0
    valleyEnter = 0
    result = 0
    for i in range (steps):
        if(path[i] == 'U'):
            level += 1
        else:
            level -= 1
        if(level < 0):
            valleyEnter = 1
        if(level == 0):
            if(valleyEnter == 1):
                valleyEnter = 0
                result += 1
        
    return result
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    steps = int(input().strip())

    path = input()

    result = countingValleys(steps, path)

    fptr.write(str(result) + '\n')

    fptr.close()
