// 백준 2294: 동전 2(골드 V), https://www.acmicpc.net/problem/2294
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static final int INF = 100001;
    static int n;
    static int k;
    static int[] coins;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        coins = new int[n];
        dp = new int[k+1];
        Arrays.fill(dp, INF);

        for(int i=0; i<n; ++i)
            coins[i] = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());

        dp[0] = 0;
        for(var coin: coins)
            for(int i=coin; i<=k; ++i)
                dp[i] = Math.min(dp[i], dp[i - coin] + 1);

        bw.write((dp[k] == INF ? -1 : dp[k]) + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}
