import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;

	public static int N;
	public static int[] A;
	public static int[] dp;

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());

		A = new int[N];
		dp = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; ++i) {
			A[i] = Integer.parseInt(st.nextToken());
			dp[i] = 1;
		}

		for (int right = 0; right < N; ++right) {
			for (int left = 0; left < right; ++left) {
				if (A[left] < A[right]) {
					dp[right] = Math.max(dp[right], dp[left] + 1);
				}
			}
		}

		Arrays.sort(dp);
		bw.write(dp[N - 1] + "\n");
		bw.flush();

		br.close();
		bw.close();
	}
}