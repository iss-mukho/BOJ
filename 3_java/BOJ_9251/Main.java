// 백준 12100: 2048(Easy), https://www.acmicpc.net/problem/12100
/*
 * 2차원 DP
 * 같은 알파벳인 경우 해당 위치에서는 글자를 추가하기 전의 LCS 값보다 1을 더해서 저장
 * 알파벳이 다른 경우 이전까지 비교한 값중 최대값
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static String word1;
    public static String word2;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        word1 = new StringTokenizer(br.readLine()).nextToken();
        word2 = new StringTokenizer(br.readLine()).nextToken();
        int l1 = word1.length();
        int l2 = word2.length();

        int[][] dp = new int[l1+1][l2+1];
        for(int i=1; i<l1+1; ++i)
            for(int j=1; j<l2+1; ++j)
                    dp[i][j] = (word1.charAt(i-1) == word2.charAt(j-1)) ? dp[i-1][j-1] + 1 : Math.max(dp[i][j-1], dp[i-1][j]);

        bw.write(dp[l1][l2] + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}
