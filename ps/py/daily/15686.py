import sys
input = sys.stdin.readline

n, m = map(int, input().split())
matrix = []
for i in range(n):
    matrix.append(list(map(int, input().split())))

house = []
chicken = []
for i in range(n):
    for j in range(n):
        if matrix[i][j] == 1:
            house.append((i, j))
        elif matrix[i][j] == 2:
            chicken.append((i, j))



