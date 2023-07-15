import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static final int INF = Integer.MAX_VALUE / 2;
    public static int n, m, a, b, c;
    public static int[][] graph;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter((new OutputStreamWriter(System.out)));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        graph = new int[n + 1][n + 1];
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                graph[i][j] = INF;

        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        for(int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            graph[a][b] = Integer.min(graph[a][b], c);
        }

        for(int m = 1; m <= n; ++m)
            for(int s = 1; s <= n; ++s)
                for(int e = 1; e <= n; ++e)
                    graph[s][e] = Integer.min(graph[s][e], graph[s][m] + graph[m][e]);

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j)
                bw.write((graph[i][j] == INF || i == j ? 0 : graph[i][j]) + " ");
            bw.write("\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
