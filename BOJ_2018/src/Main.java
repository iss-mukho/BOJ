// 백준 2018: 수들의 합 5(실버 V), https://www.acmicpc.net/problem/2018
import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N, answer = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        int left = 1;
        int right = left;

        int sum = 0;
        while(left <= N){
            if(right > N) {
                sum = 0;
                ++left;
                right = left;
                continue;
            }
            sum += right;

            if(sum == N){
                ++answer;
                sum = 0;

                ++left;
                right = left;
                continue;
            }
            if(sum > N){
                sum = 0;

                ++left;
                right = left;
                continue;
            } else
                ++right;
        }

        // 출력
        bw.write(answer + "\n");

        // 해제
        br.close();
        bw.close();
    }
}
