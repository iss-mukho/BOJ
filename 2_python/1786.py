def KMP(P, T):
    answer = []
    table = [0 for _ in range(len(T))]
    
    i = 0
    for j in range(1, len(T)):
        while i > 0 and T[i] != T[j]:
            i = table[i - 1]
        if T[i] == T[j]:
            i += 1
            table[j] = i
    
    i = 0
    for j in range(len(P)):
        while i > 0 and T[i] != P[j]:
            i = table[i - 1]
        
        if T[i] != P[j]: continue
        i += 1

        if i != len(T): continue
        answer.append(j - i + 1)
        i = table[i - 1]

    return answer

P = input()
T = input()

answer = KMP(P, T)

print(len(answer))
for ans in answer:
    print(ans + 1, end = ' ')
