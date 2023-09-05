import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))

arr.sort(reverse=True)

def binary_search(start, end):
    while start >= end:
        mid = (start + end) // 2
        sum = 0
        for i in arr:
            if i <= mid:
                break
            sum += (i - mid)
        if sum == m:
            return m
        elif sum > m:
            end = mid - 1
        else:
            start = mid + 1


print(binary_search(arr[0], arr[-1]))