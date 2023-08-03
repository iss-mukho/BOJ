import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static int N, M, K, X, A, B, answer = 0;
	static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
	static int[] dist;

	static void dijkstra(int start) {
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		pq.add(new Edge(start, 0));
		dist[start] = 0;

		while(!pq.isEmpty()) {
			int c = pq.peek().n;
			int w = pq.poll().w;

			if (dist[c] < w)
				continue;

			for(int n : graph.get(c)) {
				int nw = w + 1;

				if (nw < dist[n]) {
					dist[n] = nw;
					pq.add(new Edge(n, nw));
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken()); // 도시의 개수
		M = Integer.parseInt(st.nextToken()); // 도로의 개수
		K = Integer.parseInt(st.nextToken()); // 거리 정보
		X = Integer.parseInt(st.nextToken()); // 출발 도시의 번호

		for (int i = 0; i <= N; i++) {
			graph.add(new ArrayList<>());
		}
		dist = new int[N + 1];
		Arrays.fill(dist, Integer.MAX_VALUE / 2);

		for (int i = 0; i < M; ++i) {
			st = new StringTokenizer(br.readLine());
			A = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			graph.get(A).add(B);
		}

		dijkstra(X);

		for (int i = 1; i <= N; i++) {
			if(dist[i] != K) continue;
			bw.write(i + "\n");
			++answer;
		}

		bw.write(answer == 0 ? "-1\n" : "");
		bw.flush();
		br.close();
		bw.close();
	}
}

class Edge implements Comparable<Edge> {
	int n, w;

	Edge(int n, int w) {
		this.n = n;
		this.w = w;
	}

	@Override
	public int compareTo(Edge o) {
		return this.w - o.w;
	}
}