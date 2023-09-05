n = int(input())
w = list(map(int, input().split()))

dp = [0] * n
dp[0] = w[0]
dp[1] = max(w[0], w[1])
for i in range(2, n):
    dp[i] = max(dp[i - 1], dp[i - 2] + w[i])

print(dp[-1])