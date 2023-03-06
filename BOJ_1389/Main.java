// 백준 1389: 케빈 베이컨의 6단계 법칙(실버 I)
import java.io.*;
import java.util.Arrays;

public class Main{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static final int MAX = 1000000;
    static int N, M, a, b, answer;
    static int [][]graph;
    static int []KB;

    public static void init() {
        graph = new int[N+1][N+1];
        KB = new int[N+1];

        for(int i=1;i<=N;++i)
            Arrays.fill(graph[i], MAX);
    }
    public static void getKB() {
        for(int i=1;i<=N;++i)
            graph[i][i] = 0;

        for(int i=1;i<=N;++i)
            for(int j=1;j<=N;++j)
                if(graph[i][j] == MAX)
                    graph[i][j] = 0;

        for(int i=1;i<=N;++i)
            for(int j=1;j<=N;++j)
                KB[i] += graph[i][j];
    }
    public static int getMin() {
        int ans = 1;

        for(int i=2; i<=N; ++i)
            if(KB[ans] > KB[i])
                ans = i;

        return ans;
    }

    public static void main(String[] args) throws IOException{
        String []in = br.readLine().split(" ");
        N = Integer.parseInt(in[0]);
        M = Integer.parseInt(in[1]);
        init();

        for(int i=0;i<M;++i) {
            in = br.readLine().split(" ");
            a = Integer.parseInt(in[0]);
            b = Integer.parseInt(in[1]);

            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        for(int m=1; m<=N; ++m)
            for(int s=1; s<=N; ++s)
                for(int e=1; e<=N; ++e)
                    if(graph[s][m] > 0 && graph[m][e] > 0)
                        graph[s][e] = Math.min(graph[s][e], graph[s][m] + graph[m][e]);

        getKB();

        bw.write(getMin() + "\n");
        bw.close();
    }
}