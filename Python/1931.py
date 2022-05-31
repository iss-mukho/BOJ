import sys
input = sys.stdin.readline

N = int(input())
timelines = []
for _ in range(N):
    timelines.append(list(tuple(map(int, input().split()))))
# 종료시간-시작시간 순으로 정렬. 종료시간이 늦을수록+시작시간이 이를수록 더 많은 것을 넣을 가능성이 높다.
timelines.sort(key=lambda t: (t[1], t[0]))

cnt = 0
end_time = 0
for s, e in timelines:
    if s >= end_time:
        cnt += 1
        end_time = e

print(cnt)
