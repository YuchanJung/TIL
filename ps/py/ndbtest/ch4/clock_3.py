n = int(input())

# my code
sec = 0
for i in range(60):
    if '3' in str(i): sec += 1

minute = 0
for i in range(60):
    if '3' in str(i):
        minute += 60
    else:
        minute += sec

res = 0
for i in range(n + 1):
    if '3' in str(i):
        res += 60 * 60
    else:
        res += minute

# ndb code
# for i in range(n + 1):
#     for j in range(60):
#         for k in range(60):
#             # 매 시각 안에 ' 3' 이 포함되어 있다면 카운트 증가
#             if '3' in str(i) + str(j) + str(k): res += 1

print(res)