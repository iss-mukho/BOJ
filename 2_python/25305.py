# 백준 25305: 커트라인(브론즈 II), https://www.acmicpc.net/problem/25305
N, k = map(int, input().split())
scores = list(map(int, input().split()))
scores.sort(reverse=True)
print(scores[k-1])