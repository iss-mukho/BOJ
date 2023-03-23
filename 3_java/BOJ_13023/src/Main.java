// 백준 13023: ABCDE(골드 V), https://www.acmicpc.net/problem/13023
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int N, M, a, b;
    static boolean[] visited;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static boolean isTrue = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        for(int i=0; i<=N; ++i)
            graph.add(new ArrayList<>());

        for(int i=0; i<M; ++i){
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        for(int i=1; i<=N; ++i){
            visited = new boolean[N+1];
            DFS(i, 0);
            if(isTrue) break;
        }

        bw.write((isTrue) ? "1\n" : "0\n");
        bw.flush();

        br.close();
        bw.close();
    }

    public static void DFS(int start, int count){
        if(count == 4){
            isTrue = true;
            return;
        }

        visited[start] = true;
        for(var end: graph.get(start)){
            if(visited[end]) continue;
            DFS(end, count + 1);
        }
        visited[start] = false;
    }
}
