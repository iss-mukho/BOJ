import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static final int[] dx = {-1, +1, +0, +0, -1, -1, +1, +1};
    static final int[] dy = {+0, +0, -1, +1, -1, +1, -1, +1};

    static int[][] map;
    static boolean[][] visited;
    static int w, h;

    public static boolean inRange(int x, int y, int h, int w) {
        return 0 <= x && x < h && 0 <= y && y < w;
    }

    public static void BFS(int x, int y) {
        Deque<Dot> dq = new ArrayDeque<>();
        dq.add(new Dot(x, y));
        visited[x][y] = true;

        while(!dq.isEmpty()) {
            int cx = dq.getFirst().x;
            int cy = dq.getFirst().y;
            dq.pollFirst();

            for(int i=0; i<8; ++i) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(!inRange(nx, ny, h, w)) continue;
                if(map[nx][ny] == 0) continue;
                if(visited[nx][ny]) continue;

                visited[nx][ny] = true;
                dq.add(new Dot(nx, ny));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        while(true) {
            st = new StringTokenizer(br.readLine());
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());
            if(w == 0) break;

            map = new int[h][w];
            visited = new boolean[h][w];

            for(int i=0; i<h; ++i) {
                st = new StringTokenizer(br.readLine());
                for(int j=0; j<w; ++j)
                    map[i][j] = Integer.parseInt(st.nextToken());
            }

            int answer = 0;
            for(int i=0; i<h; ++i) {
                for(int j=0; j<w; ++j) {
                    if(visited[i][j]) continue;
                    if(map[i][j] == 0) continue;
                    BFS(i, j);
                    ++answer;
                }
            }

            bw.write(answer + "\n");
        }

        br.close();
        bw.close();
    }

    public static class Dot {
        int x;
        int y;

        Dot(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
