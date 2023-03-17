// 백준 10423: 전기가 부족해(골드 II), https://www.acmicpc.net/problem/10423
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    static int N, M, K, u, v, w;
    static int[] parent;
    static boolean[] isPower;
    static ArrayList<EDGE> edges = new ArrayList<>();
    static int answer = 0, count;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        parent = new int[N+1];
        isPower = new boolean[N+1];
        for(int i=1; i<=N; ++i) parent[i] = i;

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<K; ++i) isPower[Integer.parseInt(st.nextToken())] = true;
        count = N - K;

        for(int i=0; i<M; ++i){
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            edges.add(new EDGE(u, v, w));
        }

        // 처리
        Collections.sort(edges);
        kruskal();

        // 출력
        bw.write(answer + "\n");
        bw.flush();

        br.close();
        bw.close();
    }

    public static class EDGE implements Comparable<EDGE>{
        int s;
        int e;
        int w;

        public EDGE(int s, int e, int w) {
            this.s = s;
            this.e = e;
            this.w = w;
        }

        @Override
        public int compareTo(EDGE o) {
            return this.w - o.w;
        }
    }

    public static int findParent(int x){
        if(parent[x] != x) parent[x] = findParent(parent[x]);
        return parent[x];
    }

    public static void unionParent(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        if (a < b) parent[b] = a;
        else parent[a] = b;
    }

    public static void swap(int a, int b){
        int temp = a;
        a = b;
        b = temp;
    }

    public static void kruskal(){
        for(var edge: edges){
            u = edge.s; v = edge.e; w = edge.w;
            if(u > v) swap(u, v); // 구현 상의 편의를 위해 (u < v)

            if(isPower[u] && isPower[v]) continue; // 연결 안해도 됨
            if(findParent(u) == findParent(v)) continue; // this is cycle

            if(isPower[u] || isPower[v]){
                // 기존에 연결되어 있는 도시 중 false인 경우를 갱신시키기 위해 true 연결
                int p = u;
                while(true){
                    if(parent[p] == p) break;

                    isPower[parent[p]] = true;
                    p = parent[p];
                }

                isPower[u] = true;
                isPower[v] = true;
            }

            unionParent(u, v);
            answer += w;
        }
    }

}
