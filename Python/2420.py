N, M = map(int, input().split())
graph = [[] for _ in range(N)]

for i in range(N):
    temp = list(map(int, input().split()))
    for j in range(N):
        if i == j:
            graph[i].append(0)
        graph[i].append(temp)

lst = []
for _ in range(M):
    lst.append(list(map(int, input().split())))

