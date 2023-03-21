// 백준 1717: 집합의 표현(골드 V), https://www.acmicpc.net/problem/1717
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N, M, c, a, b;
    static int []parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력 1
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // 초기화
        parent = new int[N+1];
        for(int i=0; i<=N; ++i)
            parent[i] = i;

        // 입력 2, 처리 및 출력
        for(int i=0; i<M; ++i){
            st = new StringTokenizer(br.readLine());
            c = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            if(c == 0) unionParent(a, b);
            else{
                if(findParent(a) == findParent(b)) bw.write("YES\n");
                else bw.write("NO\n");
            }
        }
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
