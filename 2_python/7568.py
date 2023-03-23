'''
BOJ 7568번 문제
- 브루트포스 알고리즘(Silver V)
'''
class Person:
    '''
    weight, height, rank로 구성된 Person 클래스.
    '''

    def __init__(self, weight, height):
        self.weight = weight
        self.height = height
        self.rank = 1

    def increasing_rank(self):
        '''
        Increase self.rank by 1.
        '''
        self.rank += 1

    def __gt__(self, other): # self > other
        return (self.weight > other.weight) and (self.height > other.height)

    def __str__(self):
        return str(self.rank) # 문자열 형태로 return

N = int(input())
P = [] # 객체 리스트

# 입력
for _ in range(N):
    x, y = map(int, input().split())
    p = Person(x, y)
    P.append(p)

# 계산
for i in range(N):
    for j in range(N):
        if i == j:
            continue

        if P[i] > P[j]:
            P[j].increasing_rank()

# 출력
for p in P:
    print(p, end=' ')
