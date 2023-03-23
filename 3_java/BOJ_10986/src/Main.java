/**
 * 백준 10986: 나머지 합(골드 III), https://www.acmicpc.net/problem/10986
 * 1. 최소 O(N)를 요구
 * 2. 문제 상 투 포인터는 힘들듯
 * 3. 그렇다면.. 나머지? -> 나머지를 어떻게? 조합?
 *  (A % M) + (B % M) = (A + B) % M
 * 4. 나머지가 0이 아닌 것들을 어떻게 0으로 만들고, 조합을 만들 것인가?
 * 5. 4번의 전제가 잘못됨 -> (prefix[r] - prefix[l]) % M가 0이면 된다 -> 즉 나머지가 같은 것들의 순서쌍 조합을 구하면 된다.
 * 6. 조합의 크기를 고려한 자료형
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        final int MAX = 1000;

        // answer, mod[] -> 조합의 케이스는 100만^2 = 1조
        int N; int M; long answer;
        int []number; int []prefix; long[] mod = new long[MAX];

        // 입력
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        number = new int[N]; prefix = new int[N]; // 초기화

        // 숫자 입력
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i)
            number[i] = Integer.parseInt(st.nextToken()) % M;

        // 누적 합 구하기
        prefix[0] = number[0];
        for(int i=1; i<N; ++i)
            prefix[i] = (prefix[i-1] + number[i]) % M;

        // 나머지 카운팅
        for(var m: prefix)
            ++mod[m];

        /**
         * 조합 계산
         * (prefix[right] % M) == (prefix[left] % M)
         * (prefix[right] - prefix[left]) % M == 0이 만족하는 경우
         * (0) % M == 0
         * (m - m) % M == 0
         */
        answer = mod[0]; // 스스로 0이 되는 경우
        for(int i=0; i<MAX; ++i)
            answer += (mod[i] * (mod[i]-1)) / 2;

        // 출력
        bw.write(answer + "\n");

        // 해제
        br.close();
        bw.close();
    }
}
