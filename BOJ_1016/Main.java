// 백준 1016: 제곱 ㄴㄴ수(골드 I), https://www.acmicpc.net/problem/1016
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        long min = Long.parseLong(st.nextToken()), max = Long.parseLong(st.nextToken());

        final int MAX = 1000001;
        boolean []sq = new boolean[MAX];
        boolean []check = new boolean[MAX];
        Arrays.fill(sq, true);
        Arrays.fill(check, true);

        for(long i=2; i < MAX; ++i){
            if(!sq[(int)i]) continue; // 이미 제거됨

            // 제곱수 제거
            for(long j = i*i; j < MAX; j += i*i)
                sq[(int)j] = false;

            long s = (i*i) * ((min / (i*i)) + 1);
            if(min % (i*i) == 0) s = min;

            for(long j = s; j<=max; j += i*i)
                check[(int)(j - min)] = false;
        }

        int answer = 0;
        for(long i=min; i<=max; ++i)
            if(check[(int)(i-min)])
                ++answer;

        bw.write(answer + "\n");
        br.close();
        bw.close();
    }
}
