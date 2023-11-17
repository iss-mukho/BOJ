import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;

	public static final long MOD = 1000000007;
	public static int N, M, K, a, b, c, startIdx;
	public static long[] indexTree;

	public static void initTree() throws IOException {
		indexTree = new long[N * 3 + 1];

		startIdx = 1;
		while (startIdx <= N) {
			startIdx *= 2;
		}

		for (int i = 0; i < N; ++i) {
			indexTree[startIdx + i] = Long.parseLong(br.readLine());
		}

		for (int i = startIdx - 1; i > 0; --i) {
			indexTree[i] = (indexTree[i * 2] * indexTree[i * 2 + 1]) % MOD;
		}
	}

	public static void updateTree(int idx, long number) {
		indexTree[idx] = number;
		idx /= 2;

		while (idx > 0) {
			indexTree[idx] = (indexTree[idx * 2] * indexTree[idx * 2 + 1]) % MOD;
			idx /= 2;
		}
	}

	public static long multiplyTree(int left, int right) {
		long result = 1;

		while (left <= right) {
			if (left % 2 == 1) {
				result = (result * indexTree[left]) % MOD;
			}

			if (right % 2 == 0) {
				result = (result * indexTree[right]) % MOD;
			}

			left = (left + 1) / 2;
			right = (right - 1) / 2;
		}

		return result;
	}

	public static void input() throws IOException {
		st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
	}

	public static void process() throws IOException {
		for (int i = 0; i < M + K; ++i) {
			st = new StringTokenizer(br.readLine());

			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());

			if (a == 1) {
				updateTree(startIdx + b - 1, c);
			} else {
				long result = multiplyTree(startIdx + b - 1, startIdx + c - 1);
				bw.write(result + "\n");
			}
		}

		bw.flush();
	}

	public static void main(String[] args) throws IOException {
		input();
		initTree();
		process();

		br.close();
		bw.close();
	}

}
