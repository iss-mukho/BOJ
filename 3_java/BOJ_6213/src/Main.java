import java.io.*;
import java.util.*;

public class Main {
    public static int N, Q, A, B, startIdx;
    public static int[] numbers;
    public static Est[] tree;

    public static void initTree() {
        startIdx = 1;
        while(startIdx <= N)
            startIdx *= 2;

        tree = new Est[startIdx * 2];

        for(int i = 0; i < N; ++i)
            tree[startIdx + i] = new Est(numbers[i], numbers[i]);

        // Init plus
        for(int i = startIdx + N; i < startIdx * 2; ++i)
            tree[i] = new Est(1000001, 0);

        for(int i = startIdx - 1; i > 0; --i) {
            int shortest = Integer.min(tree[i * 2].shortest, tree[i * 2 + 1].shortest);
            int tallest = Integer.max(tree[i * 2].tallest, tree[i * 2 + 1].tallest);
            tree[i] = new Est(shortest, tallest);
        }
    }

    public static int getDiff(int left, int right) {
        int shortest = 1000001;
        int tallest = 0;

        while(left <= right) {
            if(left % 2 == 1) {
                shortest = Integer.min(shortest, tree[left].shortest);
                tallest = Integer.max(tallest, tree[left].tallest);
            }
            if(right % 2 == 0) {
                shortest = Integer.min(shortest, tree[right].shortest);
                tallest = Integer.max(tallest, tree[right].tallest);
            }

            left = (left + 1) / 2;
            right = (right - 1) / 2;
        }

        return tallest - shortest;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        numbers = new int[N];

        for(int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            numbers[i] = Integer.parseInt(st.nextToken());
        }
        initTree();

        for(int i = 0; i < Q; ++i) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            bw.write(getDiff(startIdx + A - 1, startIdx + B - 1) + "\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }

    public static class Est {
        int shortest;
        int tallest;

        public Est(int shortest, int tallest) {
            this.shortest = shortest;
            this.tallest = tallest;
        }
    }
}
