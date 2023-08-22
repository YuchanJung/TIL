import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    c = []
    for i in range(n):
        number = input().strip()
        c.append([number, len(number)])
    c.sort(key=lambda x:x[1])

    isConsistent = True
    for i in range(n):
        num1, l1 = c[i]
        for j in range(i + 1, n):
            flag = True
            num2, l2 = c[j]
            # print(num1, num2)
            for k in range(l1):
                if num1[k] != num2[k]:
                    flag = False
            if flag:
                isConsistent = False
                break
        if not isConsistent: break

    if isConsistent:
        print("YES")
    else:
        print("NO")


