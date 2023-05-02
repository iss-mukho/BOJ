// 백준 10217: KCM Travel(플래티넘 V), https://www.acmicpc.net/problem/10217
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static final int COST_LIMIT = 10001;

    static int T;
    static int N, M, K;
    static int u, v, c, d;
    static int[][] dist;
    static ArrayList<ArrayList<info>> graph = new ArrayList<>();

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static class info implements Comparable<info> {
        int destination;
        int time;
        int cost;

        public info(int destination, int time, int cost) {
            this.destination = destination;
            this.time = time;
            this.cost = cost;
        }

        @Override
        public int compareTo(info o) {
            return (this.time != o.time) ? this.time - o.cost : this.cost - o.time;
        }
    }

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());

        for(; T>0; T--) {
            input();
            dijkstra(1);
            output();
        }

        bw.flush();
        br.close();
        bw.close();
    }

    public static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        init();

        for(int i=0; i<K; ++i) {
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());

            graph.get(u).add(new info(v, d, c));
        }
    }

    public static void init() {
        dist = new int[N+1][M+1];
        for(var row: dist) {
            Arrays.fill(row, COST_LIMIT);
        }

        graph.clear();
        for(int i=0; i<=N; ++i) {
            graph.add(new ArrayList<>());
        }
    }

    public static void dijkstra(int start) {
        PriorityQueue<info> pq = new PriorityQueue<>();
        dist[start][0] = 0;
        pq.add(new info(start, 0, 0));

        while(!pq.isEmpty()) {
            info front = pq.poll();
            int s = front.destination;
            int t = front.time;
            int c = front.cost;

            if(dist[s][c] < t) {
                continue;
            }

            for(var nextInfo: graph.get(s)) {
                int e = nextInfo.destination;
                int nt = t + nextInfo.time;
                int nc = c + nextInfo.cost;

                if(nc > M) {
                    continue;
                }

                if(dist[e][nc] <= nt) {
                    continue;
                }

                dist[e][nc] = nt;
                pq.add(new info(e, nt, nc));
            }
        }
    }

    public static void output() throws IOException {
        int answer = getAnswer();
        bw.write((answer != COST_LIMIT ? answer : "Poor KCM") + "\n");
    }

    public static int getAnswer() {
        int answer = COST_LIMIT;
        for(int i=0; i<=M; ++i) {
            answer = Math.min(answer, dist[N][i]);
        }

        return answer;
    }

}
