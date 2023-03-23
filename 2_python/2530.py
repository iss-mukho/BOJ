H, M, S = map(int, input().split())
D = int(input())

S += D
if S >= 60:
    M += S // 60
    S %= 60

if M >= 60:
    H += M // 60
    M %= 60
    
if H >= 24:
    H %= 24

print("%d %d %d" % (H, M, S))
