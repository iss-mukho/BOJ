// 백준 2839: 설탕 배달(실버 IV), https://www.acmicpc.net/problem/2839
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int MAX = 5000;

        int N = sc.nextInt();
        int []dp = new int[MAX+1];

        Arrays.fill(dp, MAX);
        dp[3] = 1;
        dp[5] = 1;

        for(int i=6; i<=N; i+=3)
            dp[i] = dp[i-3] + 1;
        for(int i=10; i<=N; i+=5)
            dp[i] = dp[i-5] + 1;

        for(int i=8; i<=N; ++i)
            dp[i] = Math.min(dp[i-5] + dp[i-3], Math.min(dp[i-5] + 1, dp[i-3] + 1));

        System.out.println((dp[N] == MAX) ? -1 : dp[N]);
    }
}
