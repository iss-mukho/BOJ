// 백준 1976: 여행 가자(골드 IV), https://www.acmicpc.net/problem/1976
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N, M, c, a, b;
    static int[][] map;
    static int []parent;
    static int []path;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력 1
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());

        // 초기화
        parent = new int[N];
        for(int i=0; i<N; ++i)
            parent[i] = i;
        map = new int[N][N];
        path = new int[M];

        // 입력 2
        for(int i=0; i<N; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<N; ++j)
                map[i][j] = Integer.parseInt(st.nextToken());
        }

        // 입력 3
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<M; ++i)
            path[i] = Integer.parseInt(st.nextToken());

        // 처리
        for(int i=0; i<N; ++i)
            for(int j=i; j<N; ++j)
                if(map[i][j] == 1) unionParent(i, j);

        boolean isPossible = true;
        int start = path[0];
        for(int i=1; i<M; ++i){
            if(findParent(start-1) == findParent(path[i]-1)) continue;

            isPossible = false;
            break;
        }

        // 출력
        if(isPossible) bw.write("YES\n");
        else bw.write("NO\n");
        bw.flush();

        br.close();
        bw.close();
    }

    public static int findParent(int x){
        if(parent[x] != x) parent[x] = findParent(parent[x]);
        return parent[x];
    }

    public static void unionParent(int a, int b){
        a = findParent(a);
        b = findParent(b);

        if(a < b) parent[b] = a;
        else parent[a] = b;
    }

}
