import sys

def Merge(lst, left, mid, right):
    i = left
    j = mid+1
    k = left

    # 분할 정렬된 list 합병
    while i<=mid and j<=right:
        if lst[i] <= lst[j]:
            sorted[k] = lst[i]
            k += 1
            i += 1
        else:
            sorted[k] = lst[j]
            k += 1
            j += 1

    # 남아 있는 값들 일괄 복사
    if i>mid:
        for l in range(j, right+1):
            sorted[k] = lst[l]
            k += 1
    else:
        for l in range(i, mid+1):
            sorted[k] = lst[l]
            k += 1

    # 임시 리스트 sorted를 lst로 복사
    for l in range(left, right+1):
        lst[l] = sorted[l]

def MergeSort(lst, left, right):
    if left < right:
        mid = int((left+right) / 2) # 중간 위치 계산->리스트 균등 분할(분할)
        MergeSort(lst, left, mid) # 리스트 앞쪽 부분 정렬(정복)
        MergeSort(lst, mid+1, right) # 리스트 뒤쪽 부분 정렬(정복)
        Merge(lst, left, mid, right) # 정렬된 2개의 부분 배열 합병(결합)

N = int(sys.stdin.readline())
lst = []
sorted = [0] * N

for _ in range(N):
    lst.append(int(sys.stdin.readline()))

MergeSort(lst, 0, N-1)

for x in lst:
    print(x)
