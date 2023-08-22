import sys
import heapq
input = sys.stdin.readline

hq = []
n = int(input())
for i in range(n):
    heapq.heappush(hq, int(input()))

res = 0
while len(hq) > 1:
    c1 = heapq.heappop(hq)
    c2 = heapq.heappop(hq)
    merge = c1 + c2
    res += merge
    heapq.heappush(hq, merge)

print(res)