import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    b.sort()

    res = 0
    for a_item in a:
        for b_item in b:
            if a_item > b_item:
                res += 1
            else:
                break

    print(res)

# python : TLE
# pypy : AC