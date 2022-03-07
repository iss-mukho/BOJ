N = int(input())

result = 0
for _ in range(N):
    S = input()

    checking = [] # 이전에 나온 연속문자를 저장하는 리스트
    before = '' # 직전에 나온 문자를 저장하는 변수
    for x in S:
        if before == '': # 첫번째 문자
            before = x
        elif before != x: # 문자가 변경되었을때
            if before in checking: # 이미 나왔던 문자면 그룹문자가 아니다
                break
            checking.append(before) # 나오지 않았었다면 before를 checking에 저장하고
            before = x # x를 before에 저장한다.

    # 마지막 문자에 대해 판단
    if before == S[-1]: # 연속된 문자일 경우
        if before not in checking: # 기존에 존재하지 않았다면
            result += 1 # 문자열 S는 그룹 단어이다.
    else: # 연속되지 않은 문자일 경우
        if before not in checking and S[-1] not in checking: # 두 문자 다 기존에 존재하지 않아야
            result += 1 # S가 그룹 단어이다.

print(result)