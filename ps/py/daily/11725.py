from collections import deque
import sys
input = sys.stdin.readline

def bfs():
    # max = [0, 0]
    while d:
        temp = d.popleft()
        for item in tree[temp]:
            if visited[item] == 0:
                visited[item] = 1
                parent[item] = temp
                d.append(item)

    # return max

n = int(input())
tree = {}
parent = [0] * (n + 1)
visited = [0] * (n + 1)
d = deque()
for i in range(n - 1):
    n1, n2 = map(int, input().split())
    if tree.get(n1):
        tree[n1].append(n2)
    else:
        tree[n1] = [n2]
    if tree.get(n2):
        tree[n2].append(n1)
    else:
        tree[n2] = [n1]


# print(tree)
d.append(1)
visited[1] = 1
bfs()
for i in parent:
    if i != 0: print(i)