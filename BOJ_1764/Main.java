// 백준 1764: 듣보잡(실버 IV), https://www.acmicpc.net/problem/1764
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    // 입출력 버퍼
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static HashSet<String> ear = new HashSet<>();
    static HashSet<String> ans = new HashSet<>();
    static int N, M;
    static String name;

    public static void main(String[] args) throws IOException{
        // 스프링 토큰을 통한 입력(문자열)
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // 듣도
        for(int i=0; i<N; ++i) {
            st = new StringTokenizer(br.readLine());

            name = st.nextToken();
            ear.add(name);
        }
        // 보도
        for(int i=0; i<M; ++i) {
            st = new StringTokenizer(br.readLine());

            name = st.nextToken();
            // 중복이면 ans Set에 추가
            if(ear.contains(name))
                ans.add(name);
        }

        ArrayList<String> conv = new ArrayList<>(ans); // Set을 정렬하기 위해 ArrayList로 변환
        Collections.sort(conv); // 정렬

        // 출력
        bw.write(conv.size() + "\n");
        for(var n: conv)
            bw.write(n + "\n");

        // 할당 해제
        br.close();
        bw.close();
    }
}
