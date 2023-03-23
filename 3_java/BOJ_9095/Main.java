// 백준 9095: 1, 2, 3 더하기(

import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);

    static int MAX = 10;
    static int T, n;
    static int[] dp = new int[MAX + 1];

    public static void main(String[] args){
        /** 1, 2, 4, 7, 13, ...
         * 1 = 1
         * 2 = 1+1, 2
         * 3 = 1+1+1, 1+2 * 2, 3
         * 4 = 1+1+1+1, 1+1+2 * 3, 1+3 * 2, 2+2
         * 5 = 1+1+1+1+1, 1+1+1+2 * 4, 1+1+3 * 3, 1+2+2 * 3, 2+3 * 2
         * */
        // dp 초기화
        dp[1] = 1; dp[2] = 2; dp[3] = 4;
        for(int i=4; i<=MAX; ++i)
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];

        T = sc.nextInt();
        while(T-- > 0){
            n = sc.nextInt(); // 입력
            System.out.println(dp[n]); // 출력
        }
    }
}

