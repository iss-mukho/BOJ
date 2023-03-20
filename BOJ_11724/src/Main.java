// 백준 11724: 연결 요소의 개수(실버 II), https://www.acmicpc.net/problem/11724
import java.io.*;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    static int N, M, u, v, count = 0;
    static boolean[] visited;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        for(int i=0; i<=N; ++i)
            graph.add(new ArrayList<>());
        visited = new boolean[N+1];

        for(int i=0; i<M; ++i){
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());

            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        for(int i=1; i<=N; ++i){
            if(visited[i]) continue;
            BFS(i);
            ++count;
        }

        bw.write(count + "\n");
        bw.flush();

        br.close();
        bw.close();
    }

    public static void BFS(int start){
        Deque<Integer> dq = new LinkedList<>();
        dq.add(start);
        visited[start] = true;

        while(!dq.isEmpty()){
            int current = dq.pollFirst();

            for(var next: graph.get(current)){
                if(visited[next]) continue;
                visited[next] = true;
                dq.add(next);
            }
        }

    }
}
