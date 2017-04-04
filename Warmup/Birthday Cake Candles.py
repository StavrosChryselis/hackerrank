#!/bin/python3

import sys


n = int(input().strip())
height = [int(height_temp) for height_temp in input().strip().split(' ')]

mh = max(height)
rval = 0

for h in height:
    if h == mh:
        rval += 1

print(rval)
