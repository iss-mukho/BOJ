answer = 0
N = int(input())

cnt = 1
cmax = 9
cmin = 1
while True:
    if len(str(N)) == cnt:
        answer += ((N-cmin+1)*cnt)
        break
    
    answer += ((cmax-cmin+1)*cnt)
    cmax = int(str(cmax)+'9')
    cmin = int(str(cmin)+'0')
    cnt += 1

print(answer)
