// 백준 11404: 플로이드(골드 IV), https://www.acmicpc.net/problem/11404
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static final int INF = 1000000000;
    static int n, m;
    static int[][] city;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        city = new int[n][n];
        for(int i=0; i<n; ++i){
            Arrays.fill(city[i], INF);
            city[i][i] = 0;
        }

        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        for(int i=0; i<m; ++i){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken());

            city[a][b] = Integer.min(city[a][b], c);
        }

        for (int m = 0; m < n; ++m)
            for (int s = 0; s < n; ++s)
                for (int e = 0; e < n; ++e)
                    city[s][e] = Integer.min(city[s][e], city[s][m] + city[m][e]);

        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)
                bw.write(((city[i][j] == INF || i == j) ? "0" : city[i][j]) + " ");
            bw.write('\n');
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
