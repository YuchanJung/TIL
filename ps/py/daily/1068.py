from collections import deque
import sys
input = sys.stdin.readline

def bfs(del_node):
    leaf_cnt = 0
    while d:
        n = d.popleft()
        if n == del_node:
            for k, v in tree.items():
                if v[0] == n and len(tree[k]) == 1:
                    leaf_cnt += 1
            continue
        if tree.get(n):
            for item in tree[n]:
                d.append(item)
        else:
            leaf_cnt += 1
    return leaf_cnt


n = int(input())
a = list(map(int, input().split()))
del_node = int(input())

tree = {}
d = deque()
for i in range(n):
    if a[i] == -1:
        root = i
        continue
    if tree.get(a[i]):
        tree[a[i]].append(i)
    else:
        tree[a[i]] = [i]
# print(tree, root)
d.append(root)
print(bfs(del_node))