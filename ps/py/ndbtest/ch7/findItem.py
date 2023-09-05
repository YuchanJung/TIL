import sys
input = sys.stdin.readline

n = int(input().rstrip())
store = sorted(list(map(int, input().split())))
# store.sort()
m = int(input().rstrip())
target_list = list(map(int, input().split()))


def binary_search(start, end, target):
    while start <= end:
        mid = (start + end) // 2 # *************
        if store[mid] == target:
            return "yes"
        elif store[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return "no"


for item in target_list:
    print(binary_search(0, n - 1, item), end=' ')



# count sort
arr = [0] * 1000001

for i in input().split():
    arr[int(i)] = 1

for i in target_list:
    if arr[i] == 1:
        print('yes', end=' ')
    else:
        print('no', end=' ')

# set
'''
arr = set(map(int, input().split()))
for i in target_list:
    if i in arr:
        print('yes', end=' ')
    else:
        print('no', end=' ')     
'''
