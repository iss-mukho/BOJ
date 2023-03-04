/* 백준 1517: 버블 소트(플래티넘 V), https://www.acmicpc.net/problem/1517
 * Special Thank to: https://loosie.tistory.com/328
 */
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int MAX = 500000;
    static long[] number;
    static long[] index;
    static Map<Long, Integer> convert = new HashMap<>(); // 좌표 압축
    static long[] tree = new long[MAX * 3 + 1];
    static int N;
    static long cnt;

    public static void convertNumber(){
        for(int i=0; i<N; ++i)
            convert.put(number[i], i);
    }

    static long getSum(int start, int end, int node, int left, int right) {
        if(end < left || right < start) return 0;
        if(left <= start && end <= right) return tree[node];

        int mid = (start + end) / 2;
        return getSum(start, mid, node*2, left, right) + getSum(mid+1, end, node*2+1, left, right);
    }

    static void update(int start, int end, int node, int idx, int diff){
        if(start == end) {
            tree[node] = diff;
            return;
        }

        int mid = (start+end) / 2;
        if(idx <= mid) update(start, mid, node*2, idx, diff);
        else update(mid+1, end, node*2+1, idx, diff);

        tree[node] = tree[node*2] + tree[node*2+1];
    }

    public static void main(String[] args){
        // 입력
        N = sc.nextInt();
        number = new long[N];
        index = new long[N];
        for(int i=0; i<N; ++i)
            number[i] = sc.nextLong();

        // 처리
        convertNumber();
        index = number.clone();
        Arrays.sort(index);

        for(int i=0; i<N; ++i){
            int idx = convert.get(index[i]);
            cnt += getSum(0, N-1, 1, idx + 1, N - 1);
            update(0, N-1, 1, idx, 1);
        }

        // 출력
        System.out.println(cnt);
    }
}
