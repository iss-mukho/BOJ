// 백준 16234: 인구 이동, https://www.acmicpc.net/problem/16234
import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static final int[] dx = {-1, +1, +0, +0};
    static final int[] dy = {+0, +0, -1, +1};
    static int N, L, R, day = 0;
    static int[][] nations;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        nations = new int[N][N];

        for(int i=0; i<N; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<N; ++j)
                nations[i][j] = Integer.parseInt(st.nextToken());
        }

        BFS();

        bw.write(day + "\n");
        bw.flush();

        br.close();
        bw.close();
    }

    public static class pii{
        int x;
        int y;

        pii(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static boolean inRange(int x, int y){
        if(0 <= x && x < N && 0 <= y && y < N)
            return true;
        return false;
    }

    public static void BFS(){
        boolean isNoMoved = false;
        while(!isNoMoved){
            Deque<pii> dq = new ArrayDeque<>();
            boolean[][] visited = new boolean[N][N];
            isNoMoved = true;

            ++day;
            for(int i=0; i<N; ++i){
                for(int j=0; j<N; ++j){

                    if(visited[i][j]) continue;
                    Deque<pii> unionNations = new ArrayDeque();

                    dq.add(new pii(i, j));
                    unionNations.add(new pii(i, j));
                    visited[i][j] = true;
                    int nationCount = 1;
                    int unionPopulation = nations[i][j];

                    while(!dq.isEmpty()){
                        int cx = dq.peek().x;
                        int cy = dq.peek().y;
                        dq.poll();

                        for(int k=0; k<4; ++k){
                            int nx = cx + dx[k];
                            int ny = cy + dy[k];

                            if(!inRange(nx, ny)) continue;
                            if(visited[nx][ny]) continue;

                            int diff = Math.abs(nations[cx][cy] - nations[nx][ny]);
                            if(L > diff || R < diff) continue;

                            isNoMoved = false;
                            dq.add(new pii(nx, ny));
                            unionNations.add(new pii(nx, ny));
                            visited[nx][ny] = true;
                            ++nationCount;
                            unionPopulation += nations[nx][ny];
                        }
                    }

                    unionPopulation /= nationCount;
                    if(nationCount == 1) continue;
                    for(pii dot: unionNations) nations[dot.x][dot.y] = unionPopulation;
                }
            }
        }
        --day; // 마지막은 동작하지 않는 경우
    }

}
