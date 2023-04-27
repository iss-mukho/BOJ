// 백준 2293: 동전 1(골드 V), https://acmicpc.net/problem/2293
import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int k;
    static int[] number;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        number = new int[n];
        dp = new int[k+1];

        for(int i=0; i<n; ++i){
            st = new StringTokenizer(br.readLine());
            number[i] = Integer.parseInt(st.nextToken());
        }

        dp[0] = 1;
        for(int i=0; i<n; ++i)
            for(int j=number[i]; j<=k; ++j)
                dp[j] += dp[j - number[i]];

        bw.write(dp[k] + "\n");

        bw.flush();
        br.close();
        bw.close();
    }
}
