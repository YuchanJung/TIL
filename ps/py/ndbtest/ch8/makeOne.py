
x = int(input())

dp = [0] * 30001
dp[2] = dp[3] = 1
for i in range(4, x + 1):
    if i % 5 == 0:
        dp[i] = min(dp[i // 5], dp[i - 1]) + 1
    elif i % 3 == 0:
        dp[i] = min(dp[i // 3], dp[i - 1]) + 1
    elif i % 2 == 0:
        dp[i] = min(dp[i // 2], dp[i - 1]) + 1
    else:
        dp[i] = dp[i - 1] + 1
print(dp[x])