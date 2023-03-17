// 백준 1325: 효율적인 해킹(실버 I), https://www.acmicpc.net/problem/1325
import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int N, M, A, B, maxHackingCount = 0;
    static boolean[] visited;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static int[] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력 1
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // 초기화
        dist = new int[N+1];
        for(int i=0; i<=N; ++i) graph.add(new ArrayList<>());

        // 입력 2
        for(int i=0; i<M; ++i){
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            graph.get(B).add(A);
        }

        // 처리
        for(int i=1; i<=N; ++i){
            visited = new boolean[N+1];
            bfs(i);
        }

        // 출력
        for(int i=1; i<=N; ++i){
            if(dist[i] < maxHackingCount) continue;
            bw.write(i + " ");
        }
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }

    public static void bfs(int start){
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        visited[start] = true;
        ++dist[start];

        while(!q.isEmpty()){
            int current = q.poll();

            for(var next: graph.get(current)){
                if(visited[next]) continue;
                q.add(next);
                visited[next] = true;
                ++dist[start];
            }
        }

        maxHackingCount = Math.max(maxHackingCount, dist[start]);
    }

}
