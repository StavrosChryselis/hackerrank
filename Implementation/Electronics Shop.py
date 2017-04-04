#!/bin/python3

import sys


s,n,m = input().strip().split(' ')
s,n,m = [int(s),int(n),int(m)]
keyboards = [int(keyboards_temp) for keyboards_temp in input().strip().split(' ')]
pendrives = [int(pendrives_temp) for pendrives_temp in input().strip().split(' ')]

ans = -1

for k in keyboards:
    for p in pendrives:
        if k + p <= s:
            ans = max(ans, k + p)

print(ans)
