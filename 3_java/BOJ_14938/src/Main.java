// 백준 14938: 서강그라운(골드 IV), https://www.acmicpc.net/problem/14938
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static final int MAX = 10000000;
    static int n, m, r, t, a, b, l, answer = 0;
    static int[] items;
    static int[][] graph;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력 1
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());

        // 초기화
        items = new int[n];
        graph = new int[n][n];
        for(int i=0; i<n; ++i){
            Arrays.fill(graph[i], MAX);
            graph[i][i] = 0;
        }

        // 입력 2
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; ++i)
            items[i] = Integer.parseInt(st.nextToken());

        // 입력 3
        for(int i=0; i<r; ++i){
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken()) - 1;
            b = Integer.parseInt(st.nextToken()) - 1;
            l = Integer.parseInt(st.nextToken());

            graph[a][b] = l;
            graph[b][a] = l;
        }

        // 처리 1: 플로이드-워셜
        for(int m=0; m<n; ++m)
            for(int s=0; s<n; ++s)
                for(int e=0; e<n; ++e)
                    graph[s][e] = Math.min(graph[s][e], graph[s][m] + graph[m][e]);

        // 처리 2: 최대 아이템 개수
        for(int i=0; i<n; ++i){
            int temp = 0;
            for(int j=0; j<n; ++j) {
                if(graph[i][j] > m) continue;

                temp += items[j];
            }
            answer = Math.max(answer, temp);
        }

        // 출력
        bw.write(answer + "\n");

        br.close();
        bw.close();
    }

}
