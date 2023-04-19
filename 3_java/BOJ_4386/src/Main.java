// 백준 4386: 별자리 만들기(골드 III), https://www.acmicpc.net/problem/4386
import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static class Loc{
        double x;
        double y;

        public Loc(double x, double y){
            this.x = x;
            this.y = y;
        }
    }

    public static class Point{ // implements Comparable<Point>
        int index;
        double dist;

        public Point(int index, double dist) {
            this.index = index;
            this.dist = dist;
        }
    }

    static int n;
    static Loc[] loc; // 별의 위치 저장
    static ArrayList<ArrayList<Point>> edges = new ArrayList<>(); // 별의 위치를 기반으로 만든 간선 정보 저장
    static PriorityQueue<Point> pq = new PriorityQueue<>((Point x, Point y) -> {
        if (x.dist - y.dist > 0L)
            return 1;
        return -1;
    });
    static boolean[] visited;
    static double answer = 0L;

    public static double getDist(double x1, double y1, double x2, double y2){
        return Math.sqrt(Math.pow(Math.abs(x1 - x2), 2) + Math.pow(Math.abs(y1 - y2), 2));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // input
        n = Integer.parseInt(st.nextToken());
        for(int i=0; i<n; ++i)
            edges.add(new ArrayList<>());
        loc = new Loc[n];
        visited = new boolean[n];

        for(int i=0; i<n; ++i){
            st = new StringTokenizer(br.readLine());
            double x = Double.parseDouble(st.nextToken());
            double y = Double.parseDouble(st.nextToken());
            loc[i] = new Loc(x, y);
        }

        // make edges
        for(int s=0; s<n-1; ++s){
            for(int e=s+1; e<n; ++e){
                double dist = getDist(loc[s].x, loc[s].y, loc[e].x, loc[e].y);
                edges.get(s).add(new Point(e, dist));
                edges.get(e).add(new Point(s, dist));
            }
        }

        // prim algorithm
        visited[0] = true;
        for(Point point: edges.get(0)){
            pq.add(point);
        }

        while(!pq.isEmpty()){
            int start = pq.peek().index;
            double dist = pq.peek().dist;
            pq.poll();

            if(visited[start]) continue;
            visited[start] = true;
            answer += dist;

            for(Point next: edges.get(start)){
                pq.add(next);
            }
        }

        // output
        bw.write(String.format("%.2f", answer));
        bw.flush();

        br.close();
        bw.close();
    }
}
