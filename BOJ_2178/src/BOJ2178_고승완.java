// 백준 2178: 미로 탐색(실버 I), https://www.acmicpc.net/problem/2178
import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[][] maze;
    static int[][] count;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        maze = new int[N][M];
        count = new int[N][M];
        visited = new boolean[N][M];
        for(int i=0; i<N; ++i)
            Arrays.fill(count[i], 100010);

        for(int i=0; i<N; ++i){
            st = new StringTokenizer(br.readLine());
            String []temp = st.nextToken().split("");
            for(int j=0; j<M; ++j)
                maze[i][j] = Integer.parseInt(temp[j]);
        }

        BFS(0, 0);

        bw.write(count[N-1][M-1] + "\n");
        bw.flush();

        br.close();
        bw.close();
    }

    // U, D, L, R
    static int []dx = {-1, +1, +0, +0};
    static int []dy = {+0, +0, -1, +1};
    public static boolean inRange(int x, int y){
        if (0 <= x && x < N && 0 <= y && y < M)
            return true;
        return false;
    }

    public static class dot{
        int x;
        int y;

        dot(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static void BFS(int x, int y){
        Deque<dot> dq = new LinkedList<>();
        dq.add(new dot(x, y));
        count[x][y] = 1;
        visited[x][y] = true;

        while(!dq.isEmpty()){
            int cx = dq.peek().x;
            int cy = dq.peek().y;
            dq.removeFirst();

            for(int i=0; i<4; ++i){
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(!inRange(nx, ny)) continue;
                if(visited[nx][ny]) continue;
                if(maze[nx][ny] == 0) continue;
                count[nx][ny] = count[cx][cy] + 1;
                visited[nx][ny] = true;
                dq.add(new dot(nx, ny));
            }
        }
    }
}
