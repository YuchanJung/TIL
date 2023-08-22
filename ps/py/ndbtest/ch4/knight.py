n = input()

dx = [-2, -2, 2, 2, -1, -1, 1, 1]
dy = [-1, 1, -1, 1, -2, 2, -2, 2]
x_type = [0, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']

x, y = 0, int(n[1])
for i in range(1, 9):
    if x_type[i] == n[0]:
        x = i

res = 0
for i in range(8):
    nx = x + dx[i]
    ny = y + dy[i]
    if nx < 1 or ny < 1 or nx > 8 or ny > 8:
        continue
    res += 1
print(res)

#ndb code
row = int(n[1])
column = int(ord(n[0])) - int(ord('a')) + 1

'''
ord, chr -> 아스키코드 변환
ord('a') == 97
chr(97) == 'a'
'''

steps = [(-2, -1), (-2, 1), (2, -1), (2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2)]