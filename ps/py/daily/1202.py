import sys
import heapq
input = sys.stdin.readline

jewerlys = []
bags = []
h = [] # heap
n, k = map(int, input().split())
for i in range(n):
    w, v = map(int, input().split())
    jewerlys.append([w, -v])

for i in range(k):
    bags.append(int(input()))

bags.sort()
jewerlys.sort(key = lambda x:x[0])
# print(bags)
# print(jewerlys)

res = 0
i = 0
for item in bags:
    while i < n and jewerlys[i][0] <= item:
        heapq.heappush(h, jewerlys[i][1])
        i += 1
    if h: res += (-heapq.heappop(h))
print(res)