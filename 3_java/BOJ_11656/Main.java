// 백준 11656: 접미사 배열(실버 IV), https://www.acmicpc.net/problem/11656
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    // 입출력 버퍼
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static ArrayList<String> ans = new ArrayList<>();
    static String N;

    public static void main(String[] args) throws IOException{
        // 스프링 토큰을 통한 입력(문자열)
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = st.nextToken();

        // 접미사 구하기
        int len = N.length();
        for(int i=0; i<len; ++i)
            ans.add(N.substring(i, len));

        // 정렬
        Collections.sort(ans);

        // 출력
        for(var a: ans)
            bw.write(a + "\n");

        // 할당 해제
        br.close();
        bw.close();
    }
}
