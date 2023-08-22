dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

n, m = map(int, input().split())
x, y, direction = map(int, input().split())
matrix = []
visited = [m * [0] for _ in range(n)]
for i in range(n):
    matrix.append(list(map(int, input().split())))

visited[x][y] = 1
res = 1
while True:
    flag = False
    for i in range(4):
        if direction == 0: direction = 3
        else: direction -= 1
        nx = x + dx[direction]
        ny = y + dy[direction]
        if matrix[nx][ny] == 0 and visited[nx][ny] == 0:
            x, y = nx, ny
            visited[x][y] = 1
            res += 1
            flag = True
            break

    if not flag:
        x -= dx[direction]
        y -= dy[direction]
        if matrix[x][y] == 1: break

print(res)
