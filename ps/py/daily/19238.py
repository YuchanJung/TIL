import sys
input = sys.stdin.readline

dx = [None, -1, 1, 0, 0]
dy = [None, 0, 0, -1, 1]

n, m, k = map(int, input().split())
cnt, time = 0, 0
matrix = [list(map(int, input().split())) for row in range(n)]
visited = [[0] * n for row in range(n)]
smell = {}
s_loc = [[None, None] for i in range(m + 1)] # row, col
for row in range(n):
    for col in range(n):
        s_num = matrix[row][col]
        if s_num:
            s_loc[s_num] = [row, col]
            smell[s_num] = [(row, col)]
            visited[row][col] = k # smell count
s_direction = list(map(int, input().split()))
'''
priority = [
    [[2, 3, 1, 4], [4, 1, 2, 3], [3, 4, 1, 2], [4, 3, 1, 2]],
    [[2, 4, 3, 1], [2, 1, 3, 4], [3, 4, 1, 2], [4, 1, 2, 3]],
    [[4, 3, 2, 1], [1, 4, 3, 2], [1, 3, 2, 4], [3, 2, 1, 4]],
    [[3, 4, 1, 2], [3, 2, 4, 1], [1, 4, 2, 3], [1, 4, 2, 3]]
]
'''
priority = [[list(map(int, input().split())) for i in range(4)] for s in range(m)]


while(cnt < m - 1):
    for s_num in range(1, m + 1):
        if s_direction[s_num - 1] is None: continue
        x, y = s_loc[s_num]
        sp = priority[s_num - 1][s_direction[s_num - 1] - 1]
        for i in sp:
            nx, ny = x + dx[i], y + dy[i]
            
            if nx < 0 or nx >= n or ny < 0 or ny >= n: continue
            if visited[nx][ny] == 0:
                s_loc[s_num] = [nx, ny]
                s_direction[s_num - 1] = i
                break
        if s_loc[s_num] == [x, y]: # if shark did not move
            for i in sp:
                nx, ny = x + dx[i], y + dy[i]
                if nx < 0 or nx >= n or ny < 0 or ny >= n:
                    continue
                if (nx , ny) in smell[s_num]:
                    s_loc[s_num] = [nx, ny]
                    s_direction[s_num - 1] = i
                    break
    for s_num in range(1, m + 1):
        #smell count down
        del_arr = []
        for x, y in smell[s_num]:
            if visited[x][y] > 0: visited[x][y] -= 1
            if visited[x][y] == 0: del_arr.append((x, y))
        for item in del_arr: smell[s_num].remove(item)
        # shark move
        if s_direction[s_num - 1] is None: continue
        x, y = s_loc[s_num]
        if visited[x][y] == 0:
            visited[x][y] = k
            smell[s_num].append((x, y))
        else:
            if (x, y) in smell[s_num]: visited[x][y] = k
            else:
                s_loc[s_num] = [None, None]
                s_direction[s_num - 1] = None
                cnt += 1
    time += 1
    if (time > 1000):
        time = - 1
        break
print(time)