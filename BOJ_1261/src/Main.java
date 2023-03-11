// 백준 1261: 알고스팟(골드 IV), https://www.acmicpc.net/problem/1261
import java.io.*;
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    // U, D, L, R
    final static int []dx = {-1, +1, +0, +0};
    final static int []dy = {+0, +0, -1, +1};

    static int N, M;
    static int [][]graph; static int [][]broken;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력 1
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken());

        // 초기화
        graph = new int[M][N]; broken = new int[M][N];
        for(int i=0; i<M; ++i)
            Arrays.fill(broken[i], Integer.MAX_VALUE);

        // 입력 2
        for(int i=0; i<M; ++i){
            st = new StringTokenizer(br.readLine());
            String []temp = st.nextToken().split(""); // 배열에 한 글자씩 저장하기
            for(int j=0; j<N; ++j)
                graph[i][j] = Integer.parseInt(temp[j]);
        }

        // 처리: 0-1 너비 우선 탐색
        BFS(new pii(0, 0));

        // 출력
        bw.write(broken[M-1][N-1] + "\n");

        br.close();
        bw.close();
    }

    public static class pii{
        int x; int y;

        pii(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static void BFS(pii start){
        Deque<pii> dq = new LinkedList<>();
        dq.add(start);
        broken[start.x][start.y] = 0;

        while(!dq.isEmpty()){
            int cx = dq.getFirst().x, cy = dq.getFirst().y;
            dq.poll();

            for(int i=0; i<4; ++i){
                int nx = cx + dx[i], ny = cy + dy[i];

                if(!inRange(nx, ny)) continue;

                // 0-1 BFS
                int cnt = broken[cx][cy] + (graph[nx][ny] == 1 ? 1 : 0);
                if(broken[nx][ny] <= cnt) continue;

                broken[nx][ny] = cnt;
                dq.add(new pii(nx, ny));
            }
        }
    }

    public static boolean inRange(int x, int y){
        if(0 <= x && x < M && 0 <= y && y < N)
            return true;
        return false;
    }

}
