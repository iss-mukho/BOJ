S = input()

result = 0

# 단어의 길이가 작으므로, 알고리즘 자체의 효율성을 고려하지 않음.
''' 기존코드
for x in S:
    if ord(x) >= ord('A') and ord(x) <= ord('C'):
        result += 3
    elif ord(x) >= ord('D') and ord(x) <= ord('F'):
        result += 4
    elif ord(x) >= ord('G') and ord(x) <= ord('I'):
        result += 5
    elif ord(x) >= ord('J') and ord(x) <= ord('L'):
        result += 6
    elif ord(x) >= ord('M') and ord(x) <= ord('O'):
        result += 7
    elif ord(x) >= ord('P') and ord(x) <= ord('S'):
        result += 8
    elif ord(x) >= ord('T') and ord(x) <= ord('V'):
        result += 9
    elif ord(x) >= ord('W') and ord(x) <= ord('Z'):
        result += 10
'''
for x in S:
    if x in 'ABC':
        result += 3
    elif x in 'DEF':
        result += 4
    elif x in 'GHI':
        result += 5
    elif x in 'JKL':
        result += 6
    elif x in 'MNO':
        result += 7
    elif x in 'PQRS':
        result += 8
    elif x in 'TUV':
        result += 9
    elif x in 'WXYZ':
        result += 10

print(result)