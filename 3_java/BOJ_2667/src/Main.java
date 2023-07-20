import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	static final int[] dx = {-1, +1, +0, +0};
	static final int[] dy = {+0, +0, -1, +1};

	static boolean inRange(int x, int y) {
		return 0 <= x && x < N && 0 <= y && y < N;
	}

	static int[][] graph;
	static boolean[][] visited;
	static int N;

	public static int BFS(int x, int y) {
		Queue<Dot> q = new LinkedList<>();
		q.add(new Dot(x, y));
		visited[x][y] = true;

		int size = 1;
		while (!q.isEmpty()) {
			Dot cur = q.poll();
			int cx = cur.x;
			int cy = cur.y;

			for (int i = 0; i < 4; ++i) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (!inRange(nx, ny))
					continue;
				if (graph[nx][ny] == 0)
					continue;
				if (visited[nx][ny])
					continue;

				q.add(new Dot(nx, ny));
				visited[nx][ny] = true;
				++size;
			}
		}

		return size;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		N = Integer.parseInt(br.readLine());
		graph = new int[N][N];
		visited = new boolean[N][N];

		for (int i = 0; i < N; ++i) {
			String line = br.readLine();
			for (int j = 0; j < N; ++j)
				graph[i][j] = line.charAt(j) - '0';
		}

		ArrayList<Integer> answer = new ArrayList<>();
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (graph[i][j] == 0)
					continue;
				if (visited[i][j])
					continue;
				answer.add(BFS(i, j));
			}
		}

		Collections.sort(answer);
		bw.write(answer.size() + "\n");
		for (int ans : answer)
			bw.write(ans + "\n");

		bw.flush();
		br.close();
		bw.close();
	}
}

class Dot {
	int x;
	int y;

	public Dot(int x, int y) {
		this.x = x;
		this.y = y;
	}
}