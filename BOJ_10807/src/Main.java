// 백준 10807: 개수 세기(브론즈 V), https://www.acmicpc.net/problem/10807
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        final int MAX = 100;
        int N, v;
        int []number;

        // 입력 1
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        // 초기화(비트마스킹)
        number = new int[MAX * 2 + 1] ;

        // 입력 2 및 처리
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i) {
            int n = Integer.parseInt(st.nextToken());
            ++number[n + MAX];
        }

        // 입력 3
        st = new StringTokenizer(br.readLine());
        v = Integer.parseInt(st.nextToken());

        // 출력
        bw.write(number[v + MAX] + "\n");

        br.close();
        bw.close();
    }
}
