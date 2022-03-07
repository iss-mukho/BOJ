S = input()
S = S.upper()

checking = [0] * 26
for i in range(len(S)):
    checking[ord(S[i]) - 65] += 1

# 최댓값이 2개 이상인지 확인하기 위한 임시 리스트 temp
temp = checking[:]
temp.sort(reverse=True)
if temp[0] == temp[1]:
    print('?')
else:
    idx = checking.index(max(checking)) # 최대값의 index 추출
    print(chr(idx + 65))