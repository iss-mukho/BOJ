import sys

MIN_DIF = 999

def backtracking(start_idx, cnt):
    if cnt == N/2:
        global MIN_DIF
        team_start = 0
        team_link = 0

        '''
        처음에 이 부분에서 시간을 많이 잡아먹는 줄 알고 O(N^2)를 줄이고자 2시간을 투자하였다.
        하지만 그 어떤 방식으로도 해결할 수 없었다.
        '''
        for i in range(N-1):
            for j in range(i+1, N):
                if checking[i] and checking[j]:
                    team_start += team[i][j] + team[j][i] # lst[lst_[i]] 꼴의 참조는 시간을 더 잡아먹는다고 한다.
                elif not checking[i] and not checking[j]:
                    team_link += team[i][j] + team[j][i]

        dif = abs(team_start - team_link)
        MIN_DIF = min(MIN_DIF, dif)
        return

    '''
    해당 부분에서 continue를 통해 backtracking을 하면 비효율적이다.
        - 아래 구문을 사용했을 때 '시간 초과' 발생
            for i in range(N):
                if checking[i]:
                    continue 
    start_idx 변수를 통해 경우의 수를 최대한 줄여주자.
    '''
    for i in range(start_idx, N):
        checking[i] = 1
        backtracking(i + 1, cnt + 1)
        checking[i] = 0

N = int(sys.stdin.readline())
team = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

checking = [0] * N
backtracking(0, 0)

print(MIN_DIF)
