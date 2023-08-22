import sys
input = sys.stdin.readline

class Trie:
    def __init__(self):
        self.head = {}
    def add(self, word):
        cur = self.head

        for ch in word:
            if ch not in cur:
                cur[ch] = {}
            cur = cur[ch]
            if cur.get('*'):
                return False
        cur['*'] = True
        return True


t = int(input())
for _ in range(t):
    n = int(input())
    trie = Trie()
    c = []
    for i in range(n):
        number = input().strip()
        c.append([number, len(number)])
    c.sort(key=lambda x:x[1])

    isConsistenet = True
    for item in c:
        isConsistenet = trie.add(item[0])
        if not isConsistenet: break

    if isConsistenet:
        print("YES")
    else:
        print("NO")

    # print(trie.head)
