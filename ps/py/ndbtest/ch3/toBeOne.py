n, k = map(int, input().split())
result = 0
while True:
#N ==K로나누어떨어지는수가될때까지 1씩배기
    target = (n // k) * k
    result += (n - target)
    n = target
# N이 K보다 작을 때(더 이상 나눌 수 없을 때) 반복문탈출
    if n < k:
        break
    result=+ 1
    n //= k
# 마 지 악 으 로 남은 수 에 대 하 여 1 씩 빼 기
result += (n- 1)
print(result)