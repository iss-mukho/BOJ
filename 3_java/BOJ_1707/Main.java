// 백준 1707: 이분 그래프(골드 IV), https://www.acmicpc.net/problem/1707
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    static public class pii{
        int cur;
        int curColor;

        pii(int cur, int curColor){
            this.cur = cur;
            this.curColor = curColor;
        }
    }

    static int K, V, E, u, v;
    static ArrayList<Integer> []graph; // 인접 리스트
    static int []visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());

        for(int t=0; t<K; ++t) {
            st = new StringTokenizer(br.readLine());
            V = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());

            graph = new ArrayList[V];
            // 2차원 ArrayList의 각 행에 ArrayList 초기화 = 노드별 리스트
            for(int i=0; i<V; ++i)
                graph[i] = new ArrayList<Integer>();
            visited = new int[V];

            for(int i=0; i<E; ++i) {
                st = new StringTokenizer(br.readLine());
                u = Integer.parseInt(st.nextToken()) - 1;
                v = Integer.parseInt(st.nextToken()) - 1;

                graph[u].add(v);
                graph[v].add(u);
            }

            boolean isBinary = true;
            for(int x=0; x<V; ++x) {
                if(visited[x] != 0) continue;
                if(!BFS(new pii(x, 1))) {
                    isBinary = false;
                    break;
                }
            }

            if(isBinary) bw.write("YES\n");
            else bw.write("NO\n");
        }

        br.close();
        bw.close();
    }

    public static int getColor(int n) {
        if(n == 1) return 2;
        else return 1;
    }
    public static boolean BFS(pii start) {
        Deque<pii> dq = new LinkedList<>();
        dq.add(start);

        while(!dq.isEmpty()) {
            int cur = dq.peek().cur;
            int curColor = dq.peek().curColor;
            dq.poll();

            visited[cur] = curColor;
            for(var next: graph[cur]) {
                int nextColor = getColor(curColor);
                if(visited[next] != 0) {
                    if(visited[next] != nextColor) return false;
                    continue;
                }
                dq.add(new pii(next, getColor(curColor)));
            }
        }
        return true;
    }
}
