// 백준 1197: 최소 스패닝 트리(골드 IV), https://www.acmicpc.net/problem/1197
import java.io.*;
import java.util.*;

public class Main {

    static int V, E, A, B, C, answer = 0;
    static int[] parent;
    static ArrayList<edgeType> edges = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력 1
        st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        // 초기화
        parent = new int[V+1];
        for(int i=0; i<=V; ++i)
            parent[i] = i;

        // 입력 2
        for(int i=0; i<E; ++i){
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());

            edges.add(new edgeType(A, B, C));
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

    public static class edgeType implements Comparable<edgeType>{
        int s;
        int e;
        int w;

        public edgeType(int s, int e, int w) {
            this.s = s;
            this.e = e;
            this.w = w;
        }

        @Override
        public int compareTo(edgeType o) {
            return this.w - o.w;
        }
    }

    public static int findParent(int x){
        if(parent[x] != x) parent[x] = findParent(parent[x]);
        return parent[x];
    }

    public static void unionParent(int a, int b){
        a = findParent(a);
        b = findParent(b);

        if(a < b) parent[b] = a;
        else parent[a] = b;
    }

    public static void kruskal(){
        for(var edge: edges){
            A = edge.s;
            B = edge.e;
            C = edge.w;

            if(findParent(A) == findParent(B)) continue;
            unionParent(A, B);
            answer += C;
        }
    }
}
