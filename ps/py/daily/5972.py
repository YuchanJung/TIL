import heapq
import sys
input = sys.stdin.readline

inf = 90000000
graph = {}
h = [] # heap
n, m = map(int, input().split())

dist = [inf for i in range(n + 1)]
visited = [False for i in range(n + 1)]

for i in range(m):
    a, b, w = map(int, input().split())

    if graph.get(a): graph[a].append((b, w))
    else: graph[a] = [(b, w)]

    if graph.get(b): graph[b].append((a, w))
    else: graph[b] = [(a, w)]

start = 1
dist[start] = 0
heapq.heappush(h, (0, start))
while h:
    d, now = heapq.heappop(h)
    if dist[now] < d: continue
    for des, w in graph[now]:
        cur_dist = dist[des]
        dist[des] = min(cur_dist, dist[now] + w)
        if cur_dist > dist[des]:
            heapq.heappush(h, (dist[des], des))
print(dist[n])