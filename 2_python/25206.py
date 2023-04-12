# 백준 25206: 너의 평점은(실버 V), https://www.acmicpc.net/problem/25206
import sys
input = sys.stdin.readline

POINT = {
    'A+': 4.5,
    'A0': 4.0,
    'B+': 3.5,
    'B0': 3.0,
    'C+': 2.5,
    'C0': 2.0,
    'D+': 1.5,
    'D0': 1.0,
    'F': 0.0
}

gradePoint = 0
creditCount = 0
for _ in range(20):
    _, credit, grade = list(map(str, input().split()))
    if grade == 'P': continue
    credit = float(credit)

    gradePoint += (credit * POINT[grade])
    creditCount += credit

print(round(gradePoint / creditCount, 6))
