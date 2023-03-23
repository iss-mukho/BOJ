// 백준 11399: ATM(실버 IV), https://www.acmicpc.net/problem/11399

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, time = 0;
    static int[] number;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 입력
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        number = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i)
            number[i] = Integer.parseInt(st.nextToken());

        // 처리
        Arrays.sort(number);

        int prefixTime = 0;
        for(int i=1; i<=N; ++i){
            prefixTime += number[i-1];
            time += prefixTime;
        }

        // 출력
        bw.write(time + "\n");

        br.close();
        bw.close();
    }
}
