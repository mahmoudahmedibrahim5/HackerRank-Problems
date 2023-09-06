#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'isValid' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def isValid(s):
    # Write your code here
    alpha = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    array = []
    
    # Search for repeated characters
    for i in s:
        for j in range(0, 26, 1):
            if(i == alpha[j]):
                count[j] += 1
    # Make array with count of repeated characters
    for i in range(0, 26, 1):
        if(count[i] != 0):
            array.append(count[i])
    print (array)
    
    # Check if it's valid or not
    firstTime = 0 # firstTime variable for 1 character removal
    if(len(array)<3):
        repeatingNum = array[0]
    elif(array[0] == array[1]):
        repeatingNum = array[0]
    else:
        repeatingNum = array[2]
        
    for i in range (0, len(array), 1):
        if(array[i] != repeatingNum):
            firstTime += 1
            if(firstTime == 2):
                return "NO"
            else:
                if((array[i]-repeatingNum == 1) | (array[i] == 1)):
                    array[i] = repeatingNum
                else:
                    return "NO"
    return "YES"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
