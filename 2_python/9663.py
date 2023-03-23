'''
사전지식
- 이차원 리스트를 사용하면 시간 초과
- 따라서 일차원 리스트를 통해 구현해야 한다.
- 이제 대각선에 두지 않는 알고리즘을 떠올려야 한다.
'''
RESULT = 0

def promising(row):
    for r in range(row):
        # 같은 열이 아니고, 대각선 상에 있지도 않다
        if (chess[row] == chess[r]) or (abs(row-r) == abs(chess[row]-chess[r])):
            return False

    return True

def backtracking(row):
    global RESULT

    if row == N:
        RESULT += 1
        return

    for col in range(N):
        if visited[col] == 0:
            chess[row] = col
            if promising(row):
                visited[col] = 1
                backtracking(row + 1)
                visited[col] = 0

# 입력
N = int(input())
chess = [-1] * N # row번째에 col
visited = [0] * N # 해당 열은 방문됨

# 처리
backtracking(0)

# 출력
print(RESULT)
