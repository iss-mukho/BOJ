# 백준 24736: Football Scoring(브론즈 V), https://www.acmicpc.net/problem/24736
def getScore(scoreList):
    T, F, S, P, C = scoreList
    return (T * 6) + (F * 3) + (S * 2) + P + (C * 2)

A = list(map(int, input().split()))
B = list(map(int, input().split()))

print(getScore(A), getScore(B))