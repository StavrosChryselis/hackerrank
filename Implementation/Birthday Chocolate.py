#!/bin/python3

import sys

def getWays(squares, d, m):
    s = 0
    rval = 0
    for i in range(min(m, len(squares))):
        s += squares[i]
    
    if s == d:
        rval += 1
    
    for i in range(min(m, len(squares)), len(squares)):
        s -= squares[i - m]
        s += squares[i]
        if s == d:
            rval += 1
    
    return rval

n = int(input().strip())
s = list(map(int, input().strip().split(' ')))
d,m = input().strip().split(' ')
d,m = [int(d),int(m)]
result = getWays(s, d, m)
print(result)
