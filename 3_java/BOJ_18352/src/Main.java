// 백준 18352: 특정 거리의 도시 찾기(실버 II), https://www.acmicpc.net/problem/18352
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static final int INF = Integer.MAX_VALUE;

    static int N, M, K, X;
    static int A, B;
    static int[] dist;
    static ArrayList<ArrayList<edge>> edges = new ArrayList<ArrayList<edge>>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken()) - 1;
        init();

        for(int i=0; i<M; ++i){
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken()) - 1;
            B = Integer.parseInt(st.nextToken()) - 1;

            edges.get(A).add(new edge(B, 1));
        }

        // 처리
        dijkstra(X);

        // 출력
        boolean isPrint = false;
        for(int i=0; i<N; ++i){
            if(dist[i] == K){
                bw.write(i+1 + "\n");
                isPrint = true;
            }
        }
        if(!isPrint) bw.write(-1 + "\n");

        br.close();
        bw.close();
    }

    public static class edge implements Comparable<edge>{
        int next;
        int weight;

        public edge(int next, int weight){
            this.next = next;
            this.weight = weight;
        }

        @Override
        public int compareTo(edge o) {
            return this.weight - o.weight;
        }
    }

    public static void init(){
        dist = new int[N];
        Arrays.fill(dist, INF);
        for(int i=0; i<=N; ++i)
            edges.add(new ArrayList<edge>());
    }

    public static void dijkstra(int start){
        PriorityQueue<edge> pq = new PriorityQueue<>();
        dist[start] = 0;
        pq.add(new edge(start, 0));

        while(!pq.isEmpty()){
            int s = pq.peek().next;
            int w = pq.peek().weight;
            pq.remove();

            if(dist[s] < w) continue;
            for(var next: edges.get(s)){
                int e = next.next;
                int nw = w + next.weight;

                if(dist[e] > nw){
                    dist[e] = nw;
                    pq.add(new edge(e, nw));
                }
            }
        }
    }
}
