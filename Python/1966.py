from collections import deque
import heapq
# heapq는 minheap

answer = []

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    priority = list(map(int, input().split()))

    docu = deque()
    for i in range(N):
        docu.append((priority[i], i))

    # 우선 중요도 체크용
    hq = []
    for p in priority:
        heapq.heappush(hq, -p)

    cnt = 0
    while True:
        max_priority = -hq[0]
        
        # 우선순위 문서를 찾았다
        if docu[0][0] == max_priority:
            cnt += 1
            # 몇 번째인지 찾고 싶은 문서인 경우
            if docu[0][1] == M:
                answer.append(cnt)
                break
            # 아닌 경우
            docu.popleft()
            heapq.heappop(hq)
            continue
        # 못 찾은 경우
        docu.append(docu.popleft())

for a in answer:
    print(a)
