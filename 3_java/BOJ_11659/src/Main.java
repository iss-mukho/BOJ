/**
 * 백준 11659: 누적 합 구하기 4(실버 III), https://www.acmicpc.net/problem/11659
 * Q. 왜 이런 문제에 인덱스 트리를 썼나?
 * A. 억울해서
 */
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    final static int MAX = 100000;
    static int N, M, a, b, startIdx = 1;
    static int[] number = new int[MAX];
    static int[] tree = new int[MAX * 3 + 1]; // index tree

    public static void init() {
        while(startIdx <= N) startIdx *= 2;
        for(int i=0; i<N; ++i) tree[startIdx + i] = number[i];
        for(int i=startIdx-1; i>0; --i) tree[i] = tree[i*2] + tree[i*2+1];
    }
    public static int getSum(int left, int right) {
        int ans = 0;
        while(left <= right) {
            if(left % 2 == 1) ans += tree[left];
            if(right % 2 == 0) ans += tree[right];
            left = (left + 1) / 2;
            right = (right - 1) / 2;
        }
        return ans;
    }
    public static void update(int idx, int diff) {
        while(idx > 0) {
            tree[idx] += diff;
            idx /= 2;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 입력 1
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // 입력 2: 수 입력
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i)
            number[i] = Integer.parseInt(st.nextToken());

        // 트리 초기화
        init();

        // 입력 3: 구간 합 구하기
        for(int i=0; i<M; ++i) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            // 출력
            bw.write(getSum(startIdx + a - 1, startIdx + b - 1) + "\n");
        }

        br.close();
        bw.close();
    }
}
