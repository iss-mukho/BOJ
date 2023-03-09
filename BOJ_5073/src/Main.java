// 백준 5073: 삼각형과 세 변(브론즈 III), https://www.acmicpc.net/problem/5073
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

        int A, B, C;

        while(true) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());

            if(A == 0) break;

            int sum = A + B + C;
            int max = Math.max(A, Math.max(B, C));

            if (max >= sum-max) bw.write("Invalid\n");
            else if(A == B && B == C) {
                bw.write("Equilateral\n");
            }
            else if(A == B || B == C || C == A) bw.write("Isosceles\n");
            else bw.write("Scalene\n");
        }

        br.close();
        bw.close();
    }
}
