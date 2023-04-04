# 백준 1305: 광고(플래티넘 IV), https://www.acmicpc.net/problem/1305
'''
KMP 알고리즘(table)
- table[L]이 0, 즉 접두사와 중복된 채로 끝나지 않는다면 다음 광고판에 접두사로 이어질 수 없다.
- 가능한 광고의 길이 중 가장 짧은 것 = 현재 보이는 문자 중 가능한 길이 중 가장 긴 것
'''
import sys
input = sys.stdin.readline

L = int(input())
ad = input().strip() # ad가 전체 문자열이자 패턴

table = [0 for _ in range(L)]

# KMP - table
i = 0
for j in range(1, L):
    while i > 0 and ad[i] != ad[j]:
        i = table[i-1]
    if ad[i] == ad[j]:
        i += 1
        table[j] = i

print(L - table[L-1])
