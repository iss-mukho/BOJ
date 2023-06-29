const SIZE = 10;

// 인접 그래프 예시
let graph = [];
for (let i = 0; i < SIZE; ++i) {
  graph[i] = [];
}

let visited;
(visited = []).length = SIZE;
visited.fill(false);

function BFS(start) {
  const dq = [];
  dq.push(start);
  visited[start] = true;

  while (dq.length != 0) {
    const cur = dq.shift();
    console.log(cur);

    for (const next of graph[cur]) {
      if (visited[next]) continue;
      visited[next] = true;
      dq.push(next);
    }
  }
}
