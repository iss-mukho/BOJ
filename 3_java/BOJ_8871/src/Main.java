// 백준 8871: Zadanie próbne 2(브론즈 V), https://www.acmicpc.net/problem/8871
import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()) + 1;
        bw.write(n * 2 + " " + n * 3 + "\n");
        bw.flush();

        br.close();
        bw.close();
    }
}
