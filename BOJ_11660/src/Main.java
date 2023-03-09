// 백준 11660: 구간 합 구하기 5(실버 I), https://www.acmicpc.net/problem/11660
import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N, M, x1, y1, x2, y2;

        // 입력
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // 초기화
        int [][]number = new int[N+1][N+1];
        int [][]prefix = new int[N+1][N+1];

        for(int i=1; i<=N; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=N; ++j)
                number[i][j] = Integer.parseInt(st.nextToken());
        }

        // 누적 합 구하기
        for(int i=1; i<=N; ++i)
            for(int j=1; j<=N; ++j)
                prefix[i][j] = number[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];

        for(int i=0; i<M; ++i){
            st = new StringTokenizer(br.readLine());
            x1 = Integer.parseInt(st.nextToken());
            y1 = Integer.parseInt(st.nextToken());
            x2 = Integer.parseInt(st.nextToken());
            y2 = Integer.parseInt(st.nextToken());

            // 처리
            bw.write(prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1] + "\n");
        }

        br.close();
        bw.close();
    }
}
