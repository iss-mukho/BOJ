// 백준 1377: 버블 소트(골드 II), https://www.acmicpc.net/problem/1377
import java.io.*;
import java.util.Arrays;

public class Main {
    public static class pii implements Comparable<pii>{
        int value;
        int idx;

        pii(int value, int idx){
            this.value = value;
            this.idx = idx;
        }

        @Override
        public int compareTo(pii p){
            return this.value - p.value;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        pii []A = new pii[N];

        for(int i=0; i<N; ++i)
            A[i] = new pii(Integer.parseInt(br.readLine()), i);

        Arrays.sort(A, 0, N);
        int answer = -1;
        for(int i=0; i<N; ++i)
            answer = Math.max(answer, A[i].idx - i);

        bw.write(answer + 1 + "\n");
        br.close();
        bw.close();
    }
}
