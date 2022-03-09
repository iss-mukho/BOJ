import sys

min_dif = 999

def backtracking(idx, cnt):
    if cnt == N/2:
        global min_dif

        team_start = 0
        team_link = 0

        for i in range(N-1):
            for j in range(i+1, N):
                if checking[i] and checking[j]:
                    team_start += team[i][j] + team[j][i]
                elif not checking[i] and not checking[j]:
                    team_link += team[i][j] + team[j][i]

        dif = abs(team_start - team_link)
        min_dif = min(min_dif, dif)
        return

    '''
    해당 부분에서 continue를 통해 backtracking을 하면 비효율적이다.
    idx변수를 통해 경우의 수를 최대한 줄여주자.
    '''
    for i in range(idx, N):
        checking[i] = 1
        backtracking(i + 1, cnt+1)
        checking[i] = 0

N = int(sys.stdin.readline())
team = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

checking = [0] * N
backtracking(0, 0)

print(min_dif)
