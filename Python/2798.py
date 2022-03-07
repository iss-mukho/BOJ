N, M = map(int, input().split())
card = list(map(int, input().split()))

score = 0
for i in range(0, N-2):
    temp = card[i]
    for j in range(i+1, N-1):
        temp += card[j]
        for k in range(j+1, N):
            temp += card[k]
            if temp <= M and temp > score:
                score = temp
            temp -= card[k]
        temp -= card[j]
    temp -= card[i]

print(score)