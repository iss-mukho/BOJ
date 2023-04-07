// 백준 11052: 카드 구매하기(실버 I), https://www.acmicpc.net/problem/11052
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static ArrayList<Integer> cards = new ArrayList<>();
    static int []dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        dp = new int[N+1];
        cards.add(0);

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i) {
            cards.add(Integer.parseInt(st.nextToken()));
        }

        for(int i=1; i<=N; ++i){
            for(int j=1; j<=i; ++j){
                dp[i] = Integer.max(dp[i-j] + cards.get(j), dp[i]);
            }
        }
        bw.write(dp[N] + "\n");

        bw.flush();
        br.close();
        bw.close();
    }
}
