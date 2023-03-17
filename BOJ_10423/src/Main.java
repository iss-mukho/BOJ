/**
 * 백준 10423: 전기가 부족해(골드 II), https://www.acmicpc.net/problem/10423
 * 맞왜틀? -> (풀이1) 다익스트라를 발전소 기준으로 시작..? 왜요?
 *       -> (풀이2): https://steady-coding.tistory.com/123
 *              - 발전소의 부모 노드를 0으로 두고, 크루스칼 알고리즘을 돌리면서 모든 도시의 루트 노드가 0이면 종료
 *              - 발전소의 부모 노드를 0으로 두게 되면, cycle이 없는 MST를 만드는 크루스칼 알고리즘의 특성에 따라 발전소끼리 연결되지 않음
 * 그래서 대체 반례가 뭘까 -> 진짜 모름
 */
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static int N, M, K, u, v, w, answer = 0;
    static ArrayList<EDGE> edges = new ArrayList<>();
    static int[] parent;
    static boolean[] isPower;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력 1
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        // 초기화
        parent = new int[N+1];
        isPower = new boolean[N+1];
        for(int i=1; i<=N; ++i) parent[i] = i;

        // 입력 2
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<K; ++i){
            int p = Integer.parseInt(st.nextToken());
            isPower[p] = true;
            parent[p] = 0; // add
        }

        // 입력 3
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
        int s; int e; int w;

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
        a = findParent(a); b = findParent(b);
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }

    public static boolean areAllPowered(){
        for(int i=1; i<=N; ++i)
            if(!isPower[i]) return false;
        return true;
    }

    public static void kruskal(){
        for(var edge: edges){
            if(areAllPowered()) break;

            u = edge.s; v = edge.e; w = edge.w;
            if(findParent(u) == findParent(v)) continue; // this is cycle

            unionParent(u, v);
            answer += w;
        }
    }

}
