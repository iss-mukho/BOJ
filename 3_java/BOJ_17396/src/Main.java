// 백준 17396: 백도어(골드 V), https://www.acmicpc.net/problem/17396
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static final long INF = Long.MAX_VALUE / 2;
    static int N, M, a, b, t;
    static int[] visionInfo;
    static ArrayList<conn>[] graph;
    static long[] dist;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    public static class conn implements Comparable<conn> {
        int dot;
        long weight;

        public conn(int dot, long weight) {
            this.dot = dot;
            this.weight = weight;
        }

        @Override
        public int compareTo(conn o) {
            return this.weight > o.weight ? 1 : -1;
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        dijkstra(0);
        output();

        br.close();
        bw.close();
    }

    public static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        init();

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i) {
            visionInfo[i] = Integer.parseInt(st.nextToken());
        }
        visionInfo[N-1] = 0;

        for(int i=0; i<M; ++i) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            t = Integer.parseInt(st.nextToken());

            graph[a].add(new conn(b, t));
            graph[b].add(new conn(a, t));
        }
    }

    public static void init() {
        visionInfo = new int[N];

        graph = new ArrayList[N];
        for(int i=0; i<N; ++i){
            graph[i] = new ArrayList<>();
        }

        dist = new long[N];
        Arrays.fill(dist, INF);
    }

    public static void dijkstra(int start) {
        PriorityQueue<conn> pq = new PriorityQueue<>();
        dist[start] = 0;
        pq.add(new conn(start, 0));

        while(!pq.isEmpty()) {
            conn cur = pq.poll();
            int s = cur.dot;
            long w = cur.weight;

            if(dist[s] < w) {
                continue;
            }

            for(conn next: graph[s]) {
                int e = next.dot;
                long ew = w + next.weight;

                if(visionInfo[e] == 1) {
                    continue;
                }

                if(dist[e] > ew) {
                    dist[e] = ew;
                    pq.add(new conn(e, ew));
                }
            }
        }
    }

    public static void output() throws IOException {
        bw.write((dist[N-1] == INF ? -1 : dist[N-1]) + "\n");
        bw.flush();
    }
}
