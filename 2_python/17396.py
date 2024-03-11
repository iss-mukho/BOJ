import sys, heapq

input = sys.stdin.readline
INF = int(1e13)

def dijkstra():
  hq, dist = [], [INF for _ in range(N)]

  dist[0] = 0
  heapq.heappush(hq, (0, 0))

  while hq:
    w, c = heapq.heappop(hq)

    if dist[c] < w:
      continue

    for nw, n in graph[c]:
      tw = w + nw

      if isDetected[n] and n != N - 1:
        continue

      if dist[n] <= tw:
        continue

      dist[n] = tw
      heapq.heappush(hq, (tw, n))
  
  return dist[N - 1]

N, M = map(int, input().split())
graph = [[] for _ in range(N)]

isDetected = list(map(int, input().split()))

for _ in range(M):
  a, b, t = map(int, input().split())
  graph[a].append((t, b))
  graph[b].append((t, a))

minTime = dijkstra()

print(minTime if minTime != INF else -1)
