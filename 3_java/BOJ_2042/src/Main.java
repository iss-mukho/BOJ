import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int N, M, K, a, b, c, startIdx;
    public static long cL;
    public static long[] numbers;
    public static long[] tree;

    public static void initTree() {
        startIdx = 1;
        while(startIdx <= N)
            startIdx *= 2;

        tree = new long[startIdx * 2];

        for(int i = 0; i < N; ++i)
            tree[startIdx + i] = numbers[i];

        for(int i = startIdx - 1; i > 0; --i)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    public static void update(int idx, long diff) {
        while(idx > 0) {
            tree[idx] += diff;
            idx /= 2;
        }
    }

    public static long getSum(int left, int right) {
        long result = 0L;

        while(left <= right) {
            if(left % 2 == 1) result += tree[left];
            if(right % 2 == 0) result += tree[right];

            left = (left + 1) / 2;
            right = (right - 1) / 2;
        }

        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // input 1
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        // init 1
        numbers = new long[N];

        // input 2
        for(int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            numbers[i] = Long.parseLong(st.nextToken());
        }
        initTree();

        // process with index-tree and output
        for(int i = 0; i < M + K; ++i) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            if(a == 1){
                cL = Long.parseLong(st.nextToken());
                update(startIdx + b - 1, cL - tree[startIdx + b - 1]);
            }
            else {
                c = Integer.parseInt(st.nextToken());
                bw.write(Long.toString(getSum(startIdx + b - 1, startIdx + c - 1)) + "\n");
            }
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
