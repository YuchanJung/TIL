import sys
input = sys.stdin.readline

n, m = map(int, input().split())
matrix = []
for _ in range(n):
    temp = list(map(int, input().split()))
    matrix.append(min(temp))

print(max(matrix))