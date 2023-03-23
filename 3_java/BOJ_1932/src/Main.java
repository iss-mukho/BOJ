// 백준 1932: 정수 삼각형(실버 I), https://www.acmicpc.net/problem/1932
import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N, answer = -1;
        int [][]tri;
        int [][]dp;

        // 입력 1
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        // 배열 초기화
        tri = new int[N][N];
        dp = new int[N][N];

        // 입력 2
        for(int i=0; i<N; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<=i; ++j)
                tri[i][j] = Integer.parseInt(st.nextToken());
        }

        // 처리
        dp[0][0] = tri[0][0];
        for(int i=1; i<N; ++i){
            for(int j=0; j<=i; ++j){
                if(j == 0) dp[i][j] = tri[i][j] + dp[i-1][j];
                else if(j == i) dp[i][j] = tri[i][j] + dp[i-1][j-1];
                else dp[i][j] = tri[i][j] + Math.max(dp[i-1][j-1], dp[i-1][j]);
            }
        }

        for(var n: dp[N-1])
            answer = Math.max(answer, n);

        // 출력
        bw.write(answer + "\n");

        // 해제
        br.close();
        bw.close();
    }
}
