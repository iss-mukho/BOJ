import java.io.*;
import java.util.*;

public class Main {
    public static int V, E, A, B, C, answer = 0;
    public static int[] parent;
    public static ArrayList<Edge> edges = new ArrayList<>();

    public static int findParent(int x) {
        if(x != parent[x]) parent[x] = findParent(parent[x]);
        return parent[x];
    }

    public static void unionParent(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        if(a < b) parent[b] = a;
        else parent[a] = b;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        parent = new int[V + 1];
        for(int i = 1; i <= V; ++i)
            parent[i] = i;

        for(int i = 0; i < E; ++i) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());

            edges.add(new Edge(A, B, C));
        }

        Collections.sort(edges);

        for(var edge : edges) {
            int s = edge.s;
            int e = edge.e;

            if(findParent(s) == findParent(e)) continue;
            unionParent(s, e);
            answer += edge.w;
        }

        bw.write(answer + "\n");
        bw.flush();
        br.close();
        bw.close();
    }

    public static class Edge implements Comparable<Edge> {
        int s;
        int e;
        int w;

        Edge(int s, int e, int w) {
            this.s = s;
            this.e = e;
            this.w = w;
        }

        @Override
        public int compareTo(Edge o) {
            return this.w - o.w;
        }
    }
}
