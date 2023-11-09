#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'gridSearch' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING_ARRAY G
#  2. STRING_ARRAY P
#

def gridSearch(G, P):
    # Write your code here
    result = "NO"
    bigWidth = len(G[0])
    smallWidth = len(P[0])
    print("G length = " + str(bigWidth) + ", P length = " + str(smallWidth))
    for i in range(0, len(G), 1):
        for j in range(0, len(G[0]), 1):
            if (G[i][j] == P[0][0]) & ((smallWidth + j) <= bigWidth):
                flag = 0
                for k in range(0, len(P), 1):
                    for l in range(1, len(P[0]), 1):
                        if G[i+k][j+l] == P[k][l]:
                            continue
                        else:
                            flag = 1
                            break
                    if flag:
                        break
                if flag == 0:
                    result = "YES"
                    break
        if result == "YES":
            break

    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        R = int(first_multiple_input[0])

        C = int(first_multiple_input[1])

        G = []

        for _ in range(R):
            G_item = input()
            G.append(G_item)

        second_multiple_input = input().rstrip().split()

        r = int(second_multiple_input[0])

        c = int(second_multiple_input[1])

        P = []

        for _ in range(r):
            P_item = input()
            P.append(P_item)

        result = gridSearch(G, P)

        fptr.write(result + '\n')

    fptr.close()
