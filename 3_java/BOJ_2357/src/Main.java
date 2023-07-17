import java.io.*;
import java.util.*;

public class Main {
    public static int N, M, a, b, startIdx;
    public static int[] numbers;
    public static Nums[] tree;

    public static void initTree() {
        startIdx = 1;
        while(startIdx <= N)
            startIdx *= 2;

        tree = new Nums[startIdx * 2];

        for(int i = 0; i < N; ++i)
            tree[startIdx + i] = new Nums(numbers[i], numbers[i]);

        // Init plus
        for(int i = startIdx + N; i < startIdx * 2; ++i)
            tree[i] = new Nums(1000001, 0);

        for(int i = startIdx - 1; i > 0; --i) {
            int min = Integer.min(tree[i * 2].min, tree[i * 2 + 1].min);
            int max = Integer.max(tree[i * 2].max, tree[i * 2 + 1].max);
            tree[i] = new Nums(min, max);
        }
    }

    public static Nums getDiff(int left, int right) {
        int min = 1000000001;
        int max = 0;

        while(left <= right) {
            if(left % 2 == 1) {
                min = Integer.min(min, tree[left].min);
                max = Integer.max(max, tree[left].max);
            }
            if(right % 2 == 0) {
                min = Integer.min(min, tree[right].min);
                max = Integer.max(max, tree[right].max);
            }

            left = (left + 1) / 2;
            right = (right - 1) / 2;
        }

        return new Nums(min, max);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        numbers = new int[N];

        for(int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            numbers[i] = Integer.parseInt(st.nextToken());
        }
        initTree();

        for(int i = 0; i < M; ++i) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            bw.write(getDiff(startIdx + a - 1, startIdx + b - 1) + "\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }

    public static class Nums {
        int min;
        int max;

        public Nums(int min, int max) {
            this.min = min;
            this.max = max;
        }

        @Override
        public String toString() {
            return (min + " " + max);
        }
    }
}
