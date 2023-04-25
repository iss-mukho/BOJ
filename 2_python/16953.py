# 백준 16953: A → B(실버 II), https://www.acmicpc.net/problem/16953
import heapq

def calc():
    hq = []
    heapq.heappush(hq, (A, 1))

    while hq:
        cur, cnt = heapq.heappop(hq)
        if cur == B:
            return cnt

        two = int(str(cur) + '1')
        if two <= B:
            heapq.heappush(hq, (two, cnt + 1))
        one = cur * 2
        if one <= B:
            heapq.heappush(hq, (one, cnt + 1))
    
    return -1

A, B = map(int, input().split())
print(calc())
