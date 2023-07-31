import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static final int[] dx = {-1, +1, +0, +0};
	static final int[] dy = {+0, +0, -1, +1};

	static int n, m, destX, destY;
	static int[][] map;
	static int[][] answer;

	public static boolean inRange(int x, int y) {
		return 0 <= x && x < n && 0 <= y && y < m;
	}

	public static void BFS(Dot start) {
		Queue<Dot> q = new LinkedList<>();
		q.add(start);
		answer[start.x][start.y] = 0;

		while(!q.isEmpty()) {
			Dot cur = q.poll();
			int cx = cur.x;
			int cy = cur.y;

			for(int i = 0; i < 4; ++i) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if(!inRange(nx, ny)) continue;
				if(map[nx][ny] == 0) continue;

				int dest = answer[cx][cy] + 1;
				if(answer[nx][ny] <= answer[cx][cy] + 1) continue;
				answer[nx][ny] = dest;
				q.add(new Dot(nx, ny));
			}
		}
	}

	public static void main(String[] args) throws IOException {
		final int INF = Integer.MAX_VALUE / 2;

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		answer = new int[n][m];

		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 2) {
					destX = i;
					destY = j;
				}
				answer[i][j] = INF;
			}
		}

		BFS(new Dot(destX, destY));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(map[i][j] == 0) bw.write("0 ");
				else bw.write((answer[i][j] != INF ? answer[i][j] : -1) + " ");
			}
			bw.write("\n");
		}
		bw.flush();
		br.close();
		bw.close();
	}
}

class Dot {
	int x, y;

	public Dot(int x, int y) {
		this.x = x;
		this.y = y;
	}
}