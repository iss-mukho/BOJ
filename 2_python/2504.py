string = list(input())
stack = []
answer = 0
score = 1

# 스택 비교 중 여는 괄호이면 score에 2나 3을 곱해 중첩 점수 계산을 하고, 닫는 괄호가 나왔을 때 직전에 여는 괄호가 나왔다면 점수를 더해주고, 그게 아니라면 더하지 않으며 score의 중첩 점수를 그대로 나누어 준다.
for i in range(len(string)):
    if string[i] == '(':
        stack.append(string[i])
        score *= 2
    elif string[i] == '[':
        stack.append(string[i])
        score *= 3
    elif string[i] == ')':
        if len(stack) == 0 or stack[-1] == '[':
            answer = 0
            break
        if string[i-1] == '(':
            answer += score
        stack.pop()
        score //= 2
    else:
        if len(stack) == 0 or stack[-1] == '(':
            answer = 0
            break
        if string[i-1] == '[':
            answer += score
        stack.pop()
        score //= 3

print(answer if len(stack) == 0 else 0)
