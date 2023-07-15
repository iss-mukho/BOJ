import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static final int INF = Integer.MAX_VALUE / 2;

    static int V, E, K, u, v, w;
    static ArrayList<ArrayList<Dot>> graph = new ArrayList<>();
    static int[] dist;

    public static void dijkstra(int start) {
        PriorityQueue<Dot> pq = new PriorityQueue<>();
        pq.add(new Dot(start, 0));

        while(!pq.isEmpty()) {
            int s = pq.peek().next;
            int w = pq.peek().weight;
            pq.poll();

            if(dist[s] < w) continue;
            for(Dot nextDot : graph.get(s)) {
                int e = nextDot.next;
                int ew = w + nextDot.weight;

                if(dist[e] < ew) continue;
                dist[e] = ew;
                pq.add(new Dot(e, ew));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        for(int i = 0; i <= V; ++i) graph.add(new ArrayList<>());
        dist = new int[V + 1];
        for(int i = 0; i <= V; ++i) dist[i] = INF;

        st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());

        for(int i = 0; i < E; ++i) {
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            graph.get(u).add(new Dot(v, w));
        }

        dist[K] = 0;
        dijkstra(K);
        for(int i = 1; i <= V; ++i)
            bw.write(((dist[i] == INF) ? "INF" : dist[i]) + "\n");

        bw.flush();
        br.close();
        bw.close();
    }

    public static class Dot implements Comparable<Dot> {
        int next;
        int weight;

        public Dot(int next, int weight) {
            this.next = next;
            this.weight = weight;
        }

        @Override
        public int compareTo(Dot o) {
            return this.weight - o.weight;
        }
    }
}
