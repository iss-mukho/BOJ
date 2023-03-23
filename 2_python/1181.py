import sys

N = int(sys.stdin.readline())
W = [] # 좌표 객체 세트

# 입력
for _ in range(N):
    W.append(sys.stdin.readline().strip())

# 중복 제거
TEMP = set(W)

# 길이와 함께 저장
custom_word = []
for t in TEMP:
    custom_word.append([len(t), t])

# 정렬
custom_word.sort()

# 출력
for w in custom_word:
    print(w[1])
