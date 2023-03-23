// 백준 2583: 영역 구하기(실버 I), https://www.acmicpc.net/problem/2583
// BufferedWriter 출력 안됨: https://www.acmicpc.net/board/view/52639
import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    // U, D, L, R
    static int []dx = {-1, +1, +0, +0};
    static int []dy = {+0, +0, -1, +1};
    static boolean inRange(int x, int y){
        if(0 <= x && x < M && 0 <= y && y < N)
            return true;
        return false;
    }

    static int M, N, K, answer = 0;
    static boolean[][] map;
    static ArrayList<Integer> areaSize = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        input();
        process();
        output();
    }

    public static class dotType{
        int x;
        int y;

        public dotType(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void input() throws IOException {
        st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        map = new boolean[M][N];

        for(int k=0; k<K; ++k){
            st = new StringTokenizer(br.readLine());

            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            // 문제에서는 우하단이 (0, 0)이지만, 구현상 편의를 위해 좌상단을 (0,0)으로 함
            for(int i=y1; i<y2; ++i)
                for(int j=x1; j<x2; ++j)
                    map[i][j] = true;
        }
    }

    public static void process(){
        for(int i=0; i<M; ++i){
            for(int j=0; j<N; ++j){
                if(map[i][j]) continue;

                answer += 1;
                areaSize.add(BFS(new dotType(i, j)));
            }
        }
    }

    public static int BFS(dotType start){
        int size = 0;

        Deque<dotType> dq = new LinkedList<>();
        dq.add(start);
        map[start.x][start.y] = true;

        while (!dq.isEmpty()) {
            ++size;

            int cx = dq.peek().x, cy = dq.peek().y;
            dq.removeFirst();

            for(int i=0; i<4; ++i){
                int nx = cx + dx[i], ny = cy + dy[i];

                if(!inRange(nx, ny)) continue;
                if(map[nx][ny]) continue;

                dq.add(new dotType(nx, ny));
                map[nx][ny] = true;
            }
        }

        return size;
    }

    public static void output() throws IOException {
        Collections.sort(areaSize);

        bw.write(answer + "\n");
        if(answer == 0) return;

        for(var size: areaSize)
            bw.write(size + " ");
        bw.newLine();

        bw.flush();
    }

}
