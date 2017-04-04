n = int(input())
s = input()

ans = 0
val = False
curr = 0

for c in s:
    if c == 'D':
        curr -= 1
        if curr < 0:
            val = True
    
    if c == 'U':
        curr += 1
        if curr >= 0 and val:
            ans += 1
            val = False
print(ans)
