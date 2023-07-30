import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int[] numbers;
	static int N;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		N = Integer.parseInt(br.readLine());
		numbers = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) {
			numbers[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(numbers);

		int answer = Integer.MAX_VALUE;
		int left = 0;
		int right = N - 1;
		int a = 0;
		int b = 0;
		while(left < right) {
			int sum = numbers[left] + numbers[right];

			if(Math.abs(sum) < Math.abs(answer)) {
				a = numbers[left];
				b = numbers[right];
				answer = sum;
			}

			if(sum < 0) {
				left++;
			} else if (sum > 0) {
				right--;
			} else {
				break;
			}
		}

		bw.write(a + " " + b + "\n");
		bw.flush();
		br.close();
		bw.close();
	}
}