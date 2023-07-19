import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static final int INF = Integer.MAX_VALUE / 2;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int t, n, d, c, a, b, s, count, time;
    static int[] dist;
    static ArrayList<Info>[] graph;

    public static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        init();

        for(int i = 0; i < d; ++i) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            s = Integer.parseInt(st.nextToken());

            graph[b].add(new Info(a, s));
        }
    }

    public static void init() {
        dist = new int[n + 1];
        Arrays.fill(dist, INF);

        graph = new ArrayList[n + 1];
        for(int i = 0; i <= n; ++i)
            graph[i] = new ArrayList<>();
    }
    public static void dijkstra(int start) {
        PriorityQueue<Info> pq = new PriorityQueue<>();
        pq.add(new Info(start, 0));
        dist[start] = 0;

        while(!pq.isEmpty()) {
            int s = pq.peek().next;
            int w = pq.poll().time;

            if(dist[s] < w) continue;
            for(Info com : graph[s]) {
                int e = com.next;
                int nw = w + com.time;

                if(dist[e] <= nw) continue;
                dist[e] = nw;
                pq.add(new Info(e, nw));
            }
        }
    }

    public static void process() {
        count = time = 0;
        for(int i = 1; i <= n; ++i) {
            if(dist[i] == INF) continue;
            ++count;
            time = Math.max(time, dist[i]);
        }
    }

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());

        while(t-- > 0) {
            input();
            dijkstra(c);
            process();
            bw.write(count + " " + time + "\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }
}

class Info implements Comparable<Info> {
    int next;
    int time;

    public Info(int next, int time) {
        this.next = next;
        this.time = time;
    }

    @Override
    public int compareTo(Info o) {
        return this.time - o.time;
    }
}