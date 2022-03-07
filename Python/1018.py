N, M = tuple(map(int, input().split()))

board = []
for _ in range(N):
    board.append(input())

RESULT = 64
'''
처음에 기준점인 board[x][y]는 고정으로 했었으나,
기준점을 바꾸는 경우에 최소값을 가질 수 있다는 것을 간과했었다.
'''
for x in range(N-8+1):
    for y in range(M-8+1):
        TEMP1 = 0
        TEMP2 = 0
        for i in range(x, x+8):
            for j in range(y, y+8):
                '''
                Thanks to https://bambbang00.tistory.com/43
                행과 열의 시작점 a, b를 기준으로 8칸씩 모두 체크한다.
                현재 행의 번호 i, 현재 열의 번호 j의 합이 짝수이면 시작점의 색깔과 같아야 하고,
                홀수이면 시작점의 색깔과 다른 색이어야 한다.
                이를 이용하여 만약 (i+j)의 합이 짝수 일 경우,
                W가 아니라면 index1에 1을 더하고, B가 아니라면 index2에 1을 더한다.
                else문은 (i+j)의 합이 홀수인 경우로, 시작점의 색깔과 다르지 않은 경우를 체크한다.
                '''
                if (i+j) % 2 == 0:
                    if board[i][j] != 'B':
                        TEMP1 += 1
                    if board[i][j] != 'W':
                        TEMP2 += 1
                else:
                    if board[i][j] != 'W':
                        TEMP1 += 1
                    if board[i][j] != 'B':
                        TEMP2 += 1
        RESULT = min(RESULT, TEMP1, TEMP2)

print(RESULT)
