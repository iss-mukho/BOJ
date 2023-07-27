import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static final int INF = Integer.MAX_VALUE / 2;
	static int N, M, s, t, answer = 0;
	static boolean[][] height;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		height = new boolean[N][N];
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			s = Integer.parseInt(st.nextToken()) - 1;
			t = Integer.parseInt(st.nextToken()) - 1;

			height[s][t] = true;
		}

		for (int m = 0; m < N; ++m)
			for (int s = 0; s < N; ++s)
				for (int e = 0; e < N; ++e)
					if (height[s][m] && height[m][e])
						height[s][e] = true;

		for (int i = 0; i < N; ++i) {
			int cnt = 0;
			for (int j = 0; j < N; ++j)
				if (height[i][j] || height[j][i])
					++cnt;
			if (cnt == N - 1)
				++answer;
		}

		bw.write(answer + "\n");
		bw.flush();
		br.close();
		bw.close();
	}
}