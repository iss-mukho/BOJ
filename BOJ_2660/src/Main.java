// 백준 2660: 회장뽑기(골드 V), https://www.acmicpc.net/problem/2660
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static final int INF = 1234;
    static int N, a, b;
    static int[][] friend;
    static int[] score;
    static ArrayList<Integer> answer = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력 1
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        friend = new int[N][N];
        score = new int[N];
        for(int i=0; i<N; ++i)
            Arrays.fill(friend[i], INF);

        // 입력 2
        while(true){
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken()) - 1;
            b = Integer.parseInt(st.nextToken()) - 1;

            if(a == b) break;

            friend[a][b] = 1;
            friend[b][a] = 1;
        }

        // 처리 1: 플로이드 워셜
        for(int m=0; m<N; ++m)
            for(int s=0; s<N; ++s)
                for(int e=0; e<N; ++e)
                    friend[s][e] = Math.min(friend[s][e], friend[s][m] + friend[m][e]);

        // 처리 2
        int minScore = INF;
        for(int i=0; i<N; ++i) {
            friend[i][i] = 0;
            for(int j=0; j<N; ++j)
                friend[i][i] = Math.max(friend[i][i], friend[i][j]);

            score[i] = friend[i][i];
            minScore = Math.min(minScore, friend[i][i]);
        }

        // 처리 3
        for(int i=0; i<N; ++i)
            if(score[i] == minScore)
                answer.add(i+1);

        // 출력
        bw.write(minScore + " " + answer.size() + "\n");
        for(var number: answer)
            bw.write(number + " ");
        bw.flush();

        br.close();
        bw.close();
    }
}
