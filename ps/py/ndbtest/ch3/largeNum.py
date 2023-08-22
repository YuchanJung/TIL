import sys
input = sys.stdin.readline


n, m, k = map(int, input().split())
a = list(map(int, input().split()))

a.sort()
res = 0
cnt = 1
for i in range(m):
    if i != 0 and cnt % (k + 1) == 0:
        res += a[-2]
    else:
        res += a[-1]
    cnt += 1

print(res)