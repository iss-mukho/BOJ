// graph가 정사각형 꼴의 2차원 그래프라고 가정
const SIZE = 10;

function bellmanFord(graph) {
  let answer = graph.map((v) => v.slice());

  for (let m = 0; m < SIZE; ++m) {
    for (let s = 0; s < SIZE; ++s) {
      for (let e = 0; e < SIZE; ++e) {
        graph[s][e] = Math.min(graph[s][e], graph[s][m] + graph[m][e]);
      }
    }
  }

  return answer;
}
