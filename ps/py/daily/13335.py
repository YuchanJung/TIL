import sys
from collections import deque
input = sys.stdin.readline

n, w, l = map(int, input().split())
weight = list(map(int, input().split()))
d = deque()
bridge = deque()
for item in weight:
    d.append(item)

for i in range(w):
    bridge.append(0)

t = 0
bw = 0
while bridge:
    t += 1
    bw -= bridge.popleft()
    if d:
        if d[0] + bw <= l:
            bw += d[0]
            bridge.append(d.popleft())
        else:
            bridge.append(0)

print(t)
