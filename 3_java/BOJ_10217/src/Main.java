// 백준 10217: KCM Travel(플래티넘 V), https://www.acmicpc.net/problem/10217
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static final int INF = Integer.MAX_VALUE / 2; // 맞왜틀의 원인

    static int T;
    static int N, M, K;
    static int u, v, c, d;
    static int[][] dist;
    static ArrayList<ArrayList<info>> graph = new ArrayList<>(); // 인접 리스트 표현 최적화 필요?

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static class info implements Comparable<info> {
        int destination;
        int cost;
        int time;

        public info(int destination, int cost, int time) {
            this.destination = destination;
            this.cost = cost;
            this.time = time;
        }

        @Override
        public int compareTo(info o) {
            return (this.time != o.time) ? this.time - o.time : this.cost - o.cost;
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

            graph.get(u).add(new info(v, c, d));
        }
    }

    public static void init() {
        dist = new int[N+1][M+1];
        graph = new ArrayList<>(); // 여러 초기화 방법 존재

        for(int i=0; i<=N; ++i) {
            Arrays.fill(dist[i], INF);
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
            int c = front.cost;
            int t = front.time;

            if(s == N) {
                break;
            }

            if(dist[s][c] < t) {
                continue;
            }

            for(var nextInfo: graph.get(s)) {
                int e = nextInfo.destination;
                int nc = c + nextInfo.cost;
                int nt = t + nextInfo.time;

                if(nc > M) {
                    continue;
                }

                if(dist[e][nc] <= nt) {
                    continue;
                }

                // dp 최적화
                for(int i=nc; i<=M; ++i) {
                    if(dist[e][i] > nt) {
                        dist[e][i] = nt;
                    }
                }
                pq.add(new info(e, nc, nt));
            }
        }
    }

    public static void output() throws IOException {
        int answer = getAnswer();
        bw.write((answer != INF ? answer : "Poor KCM") + "\n");
        bw.flush();
    }

    public static int getAnswer() {
        int answer = INF;
        for(int i=0; i<=M; ++i) {
            answer = Math.min(answer, dist[N][i]);
        }

        return answer;
    }

}
