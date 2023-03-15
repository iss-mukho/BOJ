import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static final int INF = Integer.MAX_VALUE;

    static int V, E, K;
    static int u, v, w;
    static int[] dist;
    static ArrayList<ArrayList<edge>> edges = new ArrayList<ArrayList<edge>>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력
        st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        init();

        st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken()) - 1;

        for(int i=0; i<E; ++i){
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken()) - 1;
            v = Integer.parseInt(st.nextToken()) - 1;
            w = Integer.parseInt(st.nextToken());

            edges.get(u).add(new edge(v, w));
        }

        // 처리
        dijkstra(K);

        // 출력
        for(int i=0; i<V; ++i)
            bw.write(((dist[i] == INF) ? "INF" : dist[i]) + "\n");

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
        dist = new int[V];
        Arrays.fill(dist, INF);
        for(int i=0; i<=V; ++i)
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
