# 백준 1715: 카드 정렬하기(골드 IV), https://www.acmicpc.net/problem/1715
import sys, heapq
input = sys.stdin.readline

# 입력
N = int(input())
hq = []
for _ in range(N):
    heapq.heappush(hq, int(input()))

# 처리: 앞에서부터 순서대로 ㄴㄴ, 우선순위를 고려
answer = 0
while hq:
    before = heapq.heappop(hq)
    if not len(hq):
        break
    after = heapq.heappop(hq)

    answer += before + after
    heapq.heappush(hq, before + after)

# 출력
print(answer)
