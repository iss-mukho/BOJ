// 백준 2018: 수들의 합 5(실버 V), https://www.acmicpc.net/problem/2018
import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N, answer = 0;

        // 입력
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        // 처리: Two-Pointer
        int left = 1;
        int right = 1;

        int sum = 1;
        while(left <= right){
            if(N < right) break;
            if(sum == N) ++answer;

            if(sum < N) sum += ++right;
            else sum -= left++;
        }

        // 출력
        bw.write(answer + "\n");

        // 해제
        br.close();
        bw.close();
    }
}
