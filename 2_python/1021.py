from collections import deque

N, M = map(int, input().split())
findNumber = list(map(int, input().split()))
dq = deque([n for n in range(1, N + 1)])

count = 0
for num in findNumber:
  while True:
    if num == dq[0]:
      dq.popleft()
      break

    if dq.index(num) < len(dq) / 2:
      while num != dq[0]:
        dq.append(dq.popleft())
        count += 1
    else:
      while num != dq[0]:
        dq.appendleft(dq.pop())
        count += 1

print(count)
