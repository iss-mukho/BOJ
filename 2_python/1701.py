# 백준 1701: Cubeditor(골드 III), https://acmicpc.net/problem/1701
answer = 0
text = input()
L = len(text)

for patternStart in range(L-1):
    pattern = text[patternStart:]
    pL = L-patternStart
    
    fail = [0 for _ in range(pL)]
    i = 0
    for j in range(1, pL):
        while i>0 and pattern[i] != pattern[j]:
            i = fail[i-1]
        if pattern[i] == pattern[j]:
            i += 1
            fail[j] = i
            answer = max(answer, fail[j])

print(answer)
