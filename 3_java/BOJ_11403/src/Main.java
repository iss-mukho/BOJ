import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	static int N, a, b;
	static int[][] graph;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		N = Integer.parseInt(br.readLine());
		graph = new int[N][N];


		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++)
				graph[i][j] = Integer.parseInt(st.nextToken());
		}

		for(int m = 0; m < N; m++) {
			for(int s = 0; s < N; s++) {
				for(int e = 0; e < N; e++) {
					if(graph[s][e] == 1 || (graph[s][m] == 1 && graph[m][e] == 1))
						graph[s][e] = 1;
				}
			}
		}

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++)
				bw.write(graph[i][j] + " ");
			bw.write("\n");
		}

		bw.flush();
		br.close();
		bw.close();
	}
}
