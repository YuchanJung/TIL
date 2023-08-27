from collections import deque

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

n, m = map(int, input().split())
matrix = []
for _ in range(n):
    matrix.append(list(map(int, input())))
visited = [[False] * m for _ in range(n)]
def bfs():
    d = deque()
    d.append((0, 0))
    visited[0][0] = True
    while d:
        x, y = d.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if not visited[nx][ny]:
                matrix[nx][ny] = matrix[x][y] + 1
                visited[nx][ny] = True
                d.append((nx, ny))

bfs()
print(matrix[n - 1][m - 1])
