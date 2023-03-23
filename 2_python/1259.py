# 백준, 팰린드롬수(브1), https://www.acmicpc.net/problem/1259

while True:
    word = input()
    if word == '0':
        break
    
    cmp_word = list(word)
    cmp_word.reverse()
    print('yes' if word == ''.join(cmp_word) else 'no')
