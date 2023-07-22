import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	static int N, M, V, a, b;
	static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
	static boolean[] visited;

	public static void DFS(int num, int cnt) throws IOException {
		if(cnt == N) return;

		visited[num] = true;
		bw.write(num + " ");

		for(int nxt : graph.get(num)) {
			if(visited[nxt]) continue;
			DFS(nxt, cnt + 1);
		}
	}

	public static void BFS(int start) throws IOException {
		Queue<Integer> q = new LinkedList<>();
		q.add(start);
		visited[start] = true;

		while(!q.isEmpty()) {
			int cur = q.poll();
			bw.write(cur + " ");

			for(int nxt : graph.get(cur)) {
				if(visited[nxt]) continue;
				visited[nxt] = true;
				q.add(nxt);
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());

		for(int i = 0; i <= N; ++i)
			graph.add(new ArrayList<>());
		visited = new boolean[N + 1];

		for(int i = 0; i < M; ++i) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			graph.get(a).add(b);
			graph.get(b).add(a);
		}

		for(int i = 1; i <= N; ++i)
			Collections.sort(graph.get(i));

		// DFS
		DFS(V, 0);
		bw.write("\n");

		// BFS
		Arrays.fill(visited, false);
		BFS(V);

		bw.flush();
		br.close();
		bw.close();
	}
}
