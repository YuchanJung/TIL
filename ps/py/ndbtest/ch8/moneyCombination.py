inf = 999999
n, m = map(int, input().split())
money = []
for i in range(n):
    money.append(int(input()))

dp = [inf] * 10001
for item in money:
    dp[item] = 1

s = min(money)
for i in range(s + 1, 10001):
    for item in money:
        if i > item: dp[i] = min(dp[i], dp[i - item] + 1)

print(-1 if dp[m] == inf else dp[m])