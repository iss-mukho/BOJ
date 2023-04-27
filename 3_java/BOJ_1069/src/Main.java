// 백준 1069: 집으로(골드 III), https://www.acmicpc.net/problem/1069
import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static double X, Y, D, T;

    public static double getAnswer(){
        double answer = Math.sqrt(Math.pow(X, 2) + Math.pow(Y, 2));

        if(D >= T) {
            double remainDist = answer;
            int jumpCount = (int)(remainDist / D); // 가능한 점프 횟수
            remainDist -= (D * jumpCount);  // 남은 거리

            if(jumpCount == 0) answer = Math.min(answer, Math.min(T + (D - remainDist), T * 2)); // 걷기, 1회 점프 + 복귀, 2회 점프
            else answer = Math.min(answer, Math.min((jumpCount * T) + remainDist, (jumpCount + 1) * T)); // 걷기, n회 점프 + 걷기, n+1회 점프
        }

        return answer;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        X = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        bw.write(getAnswer() + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}
