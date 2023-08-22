
n = int(input())
command = list(map(str, input().split())) # input().split()

# my code
# start = [1, 1]
# for c in command:
#     if c == 'U':
#         if start[0] - 1 >= 1: start[0] -= 1
#     elif c == 'D':
#         if start[0] + 1 <= n: start[0] += 1
#     elif c == 'L':
#         if start[1] - 1 >= 1: start[1] -= 1
#     elif c == 'R':
#         if start[1] + 1 <= n: start[1] += 1
# print(start[0], start[1])



# ndb code
x, y = 1, 1
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
move_types = ['L', 'R', 'U', 'D']

for c in command:
    for i in range(4):
        if c == move_types[i]:
            nx = x + dx[i]
            ny = y + dy[i]
    if nx < 1 or nx > n or ny < 1 or ny > n:
        continue
    x, y = nx, ny

print(x, y)