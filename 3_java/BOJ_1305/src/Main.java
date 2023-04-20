// 백준 1305: 광고(플래티넘 IV), https://www.acmicpc.net/problem/1305
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static int L;
    static String ad;
    static int[] failTable;

    public static void KMP(String pattern) {
        int j = 0;
        for(int i=1; i<L; ++i) {
            while(j>0 && pattern.charAt(i) != pattern.charAt(j))
                j = failTable[j-1];
            if(pattern.charAt(i) == pattern.charAt(j))
                failTable[i] = ++j;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        L = Integer.parseInt(st.nextToken());
        failTable = new int[L];

        st = new StringTokenizer(br.readLine());
        ad = st.nextToken();

        KMP(ad);

        bw.write(L - failTable[L-1] + "\n");
        bw.flush();
        br.close();
        bw.close();
    }

}
