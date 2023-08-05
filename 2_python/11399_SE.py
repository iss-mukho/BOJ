N = int(input())
times = list(map(int, input().split()))
times.sort()
acc = [0] * (N + 1)

answer = 0
for i in range(1, N + 1):
    acc[i] = acc[i - 1] + times[i - 1]
    answer += acc[i]
print(answer)