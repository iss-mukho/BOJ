# 백준 1744: 수 묶기(골드 IV), https://www.acmicpc.net/problem/1744
import sys, heapq
input = sys.stdin.readline

answer = 0
plusHeapq = []
minusHq = []
convert = {
    "plus": -1,
    "minus": 1
}

def process(hq, type):
    global answer

    while hq:
        first = type * heapq.heappop(hq)
        
        if not len(hq):
            answer += first
            break

        second = type * heapq.heappop(hq)
        answer += max(first * second, first + second)

# 입력
N = int(input())
number = []

for _ in range(N):
    number.append(int(input()))

# 처리
for num in number:
    if num > 0:
        heapq.heappush(plusHeapq, -num)
    else:
        heapq.heappush(minusHq, num)

process(plusHeapq, convert["plus"])
process(minusHq, convert["minus"])

# 출력
print(answer)
