import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int n, m, c, a, b;
    static int[] parent;

    public static int findParent(int x) {
        if(parent[x] != x) parent[x] = findParent(parent[x]);
        return parent[x];
    }

    public static void unionParent(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        if(a < b) parent[b] = a;
        else parent[a] = b;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        parent = new int[n + 1];
        for(int i=1; i<n + 1; ++i)
            parent[i] = i;

        for(int i=0; i<m; ++i) {
            st = new StringTokenizer(br.readLine());
            c = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            if(c == 0) {
                unionParent(a, b);
                continue;
            }

            bw.write((findParent(a) == findParent(b)) ? "YES\n" : "NO\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
