# 백준 1931: 회의실 배정(실버 I), https://www.acmicpc.net/problem/1931
'''
Sort + Greedy

Greedy 조건?
    - 회의가 짧은 순?
    - 가장 먼저 시작하는 회의 순서?
    - 가장 빨리 끝나는 회의 순서!

아 물론, 비슷한 문제 경험이 있어서 몸이 기억하고 있는 풀이법입니다.
증명은 언젠간..
'''
import sys
input = sys.stdin.readline

# 선언
meetingCount = 0
meeting = []

# 입력
N = int(input())
for _ in range(N):
    meeting.append(tuple(map(int, input().split())))

# 처리
meeting.sort(key = lambda m: (m[1], m[0])) # 끝나는 시간 기준으로 정렬(오름차순)

currentTime = 0
for meet in meeting:
    startTime, endTime = meet

    if startTime < currentTime:
        continue

    currentTime = endTime
    meetingCount += 1

print(meetingCount)
