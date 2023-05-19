// 백준 12869: 뮤탈리스크(골드 IV), https://www.acmicpc.net/problem/12869
import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[] hp = new int[3];
    static int[][][] dp = new int[61][61][61];

    public static void init() {
        for (int i = 0; i < 61; ++i)
            for (int j = 0; j < 61; ++j)
                for (int k = 0; k < 61; ++k)
                    dp[i][j][k] = -1;
    }

    public static int process(int a, int b, int c) {
        if (a < 0) return process(0, b, c);
        if (b < 0) return process(a, 0, c);
        if (c < 0) return process(a, b, 0);

        if (a == 0 && b == 0 && c == 0) return 0;
        if (dp[a][b][c] != -1) return dp[a][b][c];

        dp[a][b][c] = Integer.MAX_VALUE;
        dp[a][b][c] = Math.min(dp[a][b][c], process(a - 9, b - 3, c - 1) + 1);
        dp[a][b][c] = Math.min(dp[a][b][c], process(a - 9, b - 1, c - 3) + 1);
        dp[a][b][c] = Math.min(dp[a][b][c], process(a - 3, b - 9, c - 1) + 1);
        dp[a][b][c] = Math.min(dp[a][b][c], process(a - 1, b - 9, c - 3) + 1);
        dp[a][b][c] = Math.min(dp[a][b][c], process(a - 3, b - 1, c - 9) + 1);
        dp[a][b][c] = Math.min(dp[a][b][c], process(a - 1, b - 3, c - 9) + 1);

        return dp[a][b][c];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            hp[i] = Integer.parseInt(st.nextToken());

        init();
        bw.write(process(hp[0], hp[1], hp[2]) + "\n");
        bw.flush();

        br.close();
        bw.close();
    }
}
