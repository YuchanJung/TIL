import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    k = input()
    l = len(k)

    s1 = []
    s2 = []
    s1_top = -1
    s2_top = -1

    for i in range(l):
        if k[i] == '<':
            if s1:
                s2.append(s1[s1_top])
                s2_top += 1
                del s1[s1_top]
                s1_top -= 1
        elif k[i] == '>':
            if s2:
                s1.append(s2[s2_top])
                s1_top += 1
                del s2[s2_top]
                s2_top -= 1
        elif k[i] == '-':
            if s1:
                del s1[s1_top]
                s1_top -= 1
        else:
            s1_top += 1
            s1.append(k[i])

    ans = ""
    for c in s1:
        if c != '\n': ans += c
    for i in range(-1, -len(s2) - 1, -1):
        ans += s2[i]
    print(ans)