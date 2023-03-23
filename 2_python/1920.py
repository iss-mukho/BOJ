def binarysearch(numbers, start, end, target):
    if start > end:
        return -1

    mid = (start+end) // 2

    if numbers[mid] == target:
        return mid
    
    if target < numbers[mid]:
        return binarysearch(numbers, start, mid-1, target)
    else:
        return binarysearch(numbers, mid+1, end, target)

N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))

A.sort()

for number in B:
    if binarysearch(A, 0, N-1, number) == -1:
        print(0)
    else:
        print(1)
