from collections import deque

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def bfs(i, j):
    global matrix, n, m
    d = deque()
    d.append((i, j))
    while d:
        x, y = d.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if matrix[nx][ny] == 0:
                matrix[nx][ny] = 1
                d.append((nx, ny))


n, m = map(int, input().split())
matrix = []
for _ in range(n):
    matrix.append(list(map(int, input()))) # map(적용할 함수, 반복 가능한 자료형)

res = 0
for i in range(n):
    for j in range(m):
        if matrix[i][j] == 0:
            bfs(i, j)
            res += 1
print(res)