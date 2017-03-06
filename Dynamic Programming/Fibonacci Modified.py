numbers = [int(n) for n in input().split()]
a = numbers[0]
b = numbers[1]
N = numbers[2]
for i in range(0, N - 2):
    res = b * b + a
    a = b
    b = res

print(res)
