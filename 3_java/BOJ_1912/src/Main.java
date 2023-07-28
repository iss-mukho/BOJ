import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	static int N, answer;
	static int[] numbers;
	static int[] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		N = Integer.parseInt(br.readLine());
		numbers = new int[N];
		dp = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			numbers[i] = Integer.parseInt(st.nextToken());

		answer = dp[0] = numbers[0];
		for(int i = 1; i < N; ++i) {
			int prefixSum = dp[i - 1] + numbers[i];
			dp[i] = Integer.max(numbers[i], prefixSum);
			answer = Integer.max(answer, dp[i]);
		}

		bw.write(answer + "\n");
		bw.flush();
		br.close();
		bw.close();
	}
}