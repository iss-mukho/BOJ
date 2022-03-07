S = input()

result = 0
i = 0
while i<len(S):
    if i < len(S)-1 and S[i:i+2] in ['c=', 'c-', 'd-', 'lj', 'nj', 's=', 'z=']:
        i += 2
    elif i < len(S)-2 and S[i:i+3] == 'dz=':
        i += 3
    else:
        i += 1
    result += 1

print(result)