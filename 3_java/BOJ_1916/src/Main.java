import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static final int INF = Integer.MAX_VALUE / 2;
    public static int N, M, s, e, w, START, END;
    public static ArrayList<ArrayList<Edge>> graph = new ArrayList<>();
    public static int[] dist;

    public static void dijkstra(int start) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(start, 0));
        dist[start] = 0;

        while(!pq.isEmpty()) {
            int s = pq.peek().node;
            int w = pq.poll().weight;
            if(dist[s] < w) continue;

            for(Edge next : graph.get(s)) {
                int e = next.node;
                int nw = w + next.weight;
                if(dist[e] <= nw) continue;
                dist[e] = nw;
                pq.add(new Edge(e, nw));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        dist = new int[N + 1];
        Arrays.fill(dist, INF);
        for(int i = 0; i <= N; ++i)
            graph.add(new ArrayList<>());

        M = Integer.parseInt(br.readLine());

        for(int i = 0; i < M; ++i) {
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            graph.get(s).add(new Edge(e, w));
        }

        st = new StringTokenizer(br.readLine());
        START = Integer.parseInt(st.nextToken());
        END = Integer.parseInt(st.nextToken());

        dijkstra(START);

        bw.write(dist[END] + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}

class Edge implements Comparable<Edge> {
    int node;
    int weight;

    public Edge(int node, int weight) {
        this.node = node;
        this.weight = weight;
    }

    @Override
    public int compareTo(Edge o) {
        return this.weight - o.weight;
    }
}