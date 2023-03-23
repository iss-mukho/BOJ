'''
BOJ 11650번 문제
- 정렬(Silver V)
'''
import sys

class Coordinate:
    '''
    x, y 좌표값으로 구성된 Coordinate 클래스.
    '''

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other): # self < other
        if self.x < other.x:
            return True
        elif self.x == other.x:
            return True if self.y < other.y else False
        else:
            return False

    def __str__(self):
        return f"{self.x} {self.y}" # 문자열 형태로 return

N = int(sys.stdin.readline())
C = [] # 좌표 객체 리스트

# 입력
for _ in range(N):
    x, y = map(int, sys.stdin.readline().split())
    c = Coordinate(x, y)
    C.append(c)

# 정렬
C.sort(key=lambda c: (c.x, c.y))

# 출력
for c in C:
    print(c)
