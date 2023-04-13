// 백준 14466: 소가 길을 건너간 이유 6(골드 IV), https://www.acmicpc.net/problem/14466
import java.io.*;
import java.util.*;

public class Main {
    static class loc{
        int x, y;
        loc(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static final int[] dx = {-1, +1, +0, +0};
    static final int[] dy = {+0, +0, -1, +1};
    static boolean inRange(int x, int y){
        return 1 <= x && x <= N && 1 <= y && y <= N;
    }

    static int N, K, R, x, y, r, c, answer = 0;
    static ArrayList<loc>[][] roads; // 해당 위치에서 막힌 방향의 좌표를 저장
    static ArrayList<loc> cowLocation = new ArrayList<>();
    static int[][] visited; // 0: 방문 X, 1: 방문하지 않은 소의 위치, 2: 방문 O

    public static void reset(){
        for(int i=1; i<=N; ++i)
            Arrays.fill(visited[i], 0);
        for(loc l: cowLocation)
            visited[l.x][l.y] = 1;
    }

    public static int BFS(loc start){
        int ans = cowLocation.size()-1;
        Deque<loc> dq = new ArrayDeque<>();
        reset();

        dq.add(start);
        visited[start.x][start.y] = 2;

        while(!dq.isEmpty()){
            int cx = dq.peek().x, cy = dq.peek().y;
            dq.removeFirst();

            for(int i=0; i<4; ++i){
                int nx = cx + dx[i], ny = cy + dy[i];

                if(!inRange(nx, ny)) continue;
                if(visited[nx][ny] == 2) continue;

                boolean isCannotGoNext = false;
                for(loc r: roads[cx][cy]){
                    if(nx != r.x || ny != r.y) continue;
                    isCannotGoNext = true;
                    break;
                }
                if(isCannotGoNext) continue;

                if(visited[nx][ny] == 1) --ans;
                visited[nx][ny] = 2;
                dq.add(new loc(nx, ny));
            }
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        roads = new ArrayList[N+1][N+1];
        for(int i=1; i<=N; ++i)
            for(int j=1; j<=N; ++j)
                roads[i][j] = new ArrayList<>();
        visited = new int[N+1][N+1];

        for(int i=0; i<R; ++i){
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            roads[x][y].add(new loc(r, c));
            roads[r][c].add(new loc(x, y));
        }

        for(int i=0; i<K; ++i){
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            cowLocation.add(new loc(x, y));
        }

        for(loc start: cowLocation){
            answer += BFS(start);
            if(answer == 0) break;
        }

        bw.write(answer/2 + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}
