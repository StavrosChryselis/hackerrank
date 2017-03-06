#!/bin/python3

import sys
n = int(input().strip())

prod = 1

for i in range(2, n + 1):
    prod = prod * i
    
print(prod)
