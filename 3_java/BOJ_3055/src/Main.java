// 백준 3055: 탈출(골드 IV), https://www.acmicpc.net/problem/3055
import java.io.*;
import java.util.*;

public class Main {
    static final int INF = -1;
    // U, D, L, R
    static final int[] dx = {-1, +1, +0, +0};
    static final int[] dy = {+0, +0, -1, +1};

    static int R, C;
    static char[][] forest;
    static int[][] visitedTime;
    static int[][] waterTime;
    static pii start, destination;
    static ArrayList<pii> waters = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력 1
        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        // 초기화
        forest = new char[R][C];
        visitedTime = new int[R][C];
        waterTime = new int[R][C];
        for(int i=0; i<R; ++i) {
            Arrays.fill(visitedTime[i], INF);
            Arrays.fill(waterTime[i], INF);
        }

        // 입력 2
        for(int i=0; i<R; ++i){
            st = new StringTokenizer(br.readLine());
            char[] line = st.nextToken().toCharArray();

            for(int j=0; j<C; ++j){
                forest[i][j] = line[j];

                if(line[j] == '*') {
                    waters.add(new pii(i, j));
                    continue;
                }
                if(line[j] == 'D'){
                    destination = new pii(i, j);
                    continue;
                }
                if(line[j] == 'S'){
                    start = new pii(i, j);
                    continue;
                }
            }
        }

        // 처리
        waterBFS();
        hedgehogBFS(start);

        // 출력
        int x = destination.x, y = destination.y;
        bw.write(((visitedTime[x][y] != -1) ? visitedTime[x][y] : "KAKTUS") + "\n");
        bw.flush();

        br.close();
        bw.close();
    }

    public static class pii{
        int x, y;

        public pii(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static boolean inRange(int x, int y){
        if(0 <= x && x < R && 0 <= y && y < C)
            return true;
        return false;
    }

    public static void waterBFS() {
        Deque<pii> dq = new ArrayDeque<>();
        for(pii waterDot: waters) {
            dq.add(waterDot);
            waterTime[waterDot.x][waterDot.y] = 0;
        }

        while (!dq.isEmpty()) {
            int cx = dq.peek().x, cy = dq.peek().y;
            dq.poll();

            for (int i = 0; i < 4; ++i) {
                int nx = cx + dx[i], ny = cy + dy[i];

                if (!inRange(nx, ny)) continue;
                if (forest[nx][ny] == 'X') continue;
                if (forest[nx][ny] == 'D') continue;
                if (waterTime[nx][ny] != -1) continue;

                waterTime[nx][ny] = waterTime[cx][cy] + 1;
                dq.add(new pii(nx, ny));
            }
        }
    }

    public static void hedgehogBFS(pii start) {
        Deque<pii> dq = new ArrayDeque<>();
        dq.add(start);
        visitedTime[start.x][start.y] = 0;

        while (!dq.isEmpty()) {
            int cx = dq.peek().x, cy = dq.peek().y;
            dq.poll();

            for (int i = 0; i < 4; ++i) {
                int nx = cx + dx[i], ny = cy + dy[i];

                if (!inRange(nx, ny)) continue;
                if (forest[nx][ny] == 'X') continue;
                if (visitedTime[nx][ny] != -1) continue;
                if (waterTime[nx][ny] != -1 && visitedTime[cx][cy] + 1 >= waterTime[nx][ny]) continue;

                visitedTime[nx][ny] = visitedTime[cx][cy] + 1;
                dq.add(new pii(nx, ny));
            }
        }
    }
}
