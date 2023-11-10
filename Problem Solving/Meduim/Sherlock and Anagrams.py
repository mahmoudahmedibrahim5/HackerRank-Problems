#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'sherlockAndAnagrams' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def sherlockAndAnagrams(s):
    # Write your code here
    result = 0
    sub1 = s[0]
    sub2 = s[1]
    for i in range(1, len(s), 1):
        for j in range(0, len(s)-i, 1):
            sub1 = s[j:j+i]
            for k in range(j+1, len(s)-i+1, 1):
                sub2 = s[k:k+i]
                if sorted(sub1) == sorted(sub2):
                    result += 1

    return result
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = sherlockAndAnagrams(s)

        fptr.write(str(result) + '\n')

    fptr.close()
