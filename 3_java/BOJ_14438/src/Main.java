import java.io.*;
import java.util.*;

public class Main {
    public static final int INF = 1000000001;
    public static int N, M, q, a, b, startIdx = 1;
    public static int[] tree;
    public static int[] number;

    public static void initTree() {
        while (startIdx <= N) startIdx *= 2;
        tree = new int[startIdx * 2];
        for(int i = 0; i < N; ++i) tree[startIdx + i] = number[i];
        for(int i = startIdx - 1; i > 0; --i) tree[i] = Integer.min(tree[i * 2], tree[i * 2 + 1]);
    }

    public static void update(int idx, int newNumber) {
        tree[idx] = newNumber;
        idx /= 2;
        while(idx > 0) {
            tree[idx] = Integer.min(tree[idx * 2], tree[idx * 2 + 1]);
            idx /= 2;
        }
    }

    public static int getMinValue(int left, int right) {
        int result = INF;
        while(left <= right) {
            if(left % 2 == 1) result = Integer.min(result, tree[left]);
            if(right % 2 == 0) result = Integer.min(result, tree[right]);
            left = (left + 1) / 2;
            right = (right - 1) / 2;
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        number = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; ++i) number[i] = Integer.parseInt(st.nextToken());

        initTree();

        M = Integer.parseInt(br.readLine());
        for(int i = 0; i < M; ++i) {
            st = new StringTokenizer(br.readLine());
            q = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            if(q == 1) update(startIdx + a - 1, b);
            else bw.write(getMinValue(startIdx + a - 1, startIdx + b - 1) + "\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }
}