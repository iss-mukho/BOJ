// 백준 10714: 케이크 자르기 2(골드 II), https://www.acmicpc.net/problem/10714
import java.util.Arrays;
import java.util.Scanner;

/**
 * i를 기준으로 왼쪽은 i-1, 오른쪽은 i+1
 * 최대값 = dp[l][r]
 *
 * l-1번째와 r+1번째 중 선택
 *  - joi: 결과적으로 더 큰 값을 갖게 되는 쪽 선택
 *  - ioi: max(dp[l-1], dp[r+1])
 */
public class Main {
    static int MAX = 2000;
    static Scanner sc = new Scanner(System.in);
    static long [] number = new long[MAX+1];
    static long[][] dp = new long[MAX+1][MAX+1];
    static long answer = 0;
    static int N, num;

    /**
     * minus, plus = 작은 수, 큰 수의 주소값 반환
     * int l, int r = 함수의 확실한 이해를 위해 x가 아닌 l, r로 표현
     */
    static int minus(int l){
        return (l + N - 1) % N;
    }
    static int plus(int r){
        return (r + 1) % N;
    }

    // ioi가 먹을 때, joi가 가장 많이 먹을 수 있는 경우
    static long ioi(int l, int r){
        // ioi가 먹으면 joi가 먹을 수 없음
        if(plus(r) == l)
            return 0;

        // joi가 가장 많이 먹도록 유도
        if(number[minus(l)] > number[plus(r)])
            return joi(minus(l), r);
        return joi(l, plus(r));
    }

    // joi가 먹을 때, 가장 많이 먹는 경우
    static long joi(int l, int r){
        if(dp[l][r] != -1) return dp[l][r]; // 값이 있는 경우 반환
        if(plus(r) == l) return dp[l][r] = 0; // 이미 먹은 것은 못먹음

        // joi가 선택한 것과 ioi가 선택(joi가 최대가 되도록 유도한 값)한 것 비교
        long l1 = number[minus(l)] + ioi(minus(l), r);
        long l2 = number[plus(r)] + ioi(l, plus(r));

        // 반환과 동시에 할당
        if(l1 > l2)
            return dp[l][r] = l1;
        return dp[l][r] = l2;
    }

    public static void main(String[] args){
        // 초기화
        for(int i=0; i<MAX+1; ++i)
            Arrays.fill(dp[i], -1);

        // 입력
        N = sc.nextInt();
        for(int i=0; i<N; ++i){
            num = sc.nextInt();
            number[i] = num;
        }

        // 처리
        answer = 0;
        for(int i=0; i<N; ++i)
            answer = Math.max(answer, number[i] + ioi(i, i)); // Let's go recursion + DP

        // 출력
        System.out.println(answer);
    }
}
