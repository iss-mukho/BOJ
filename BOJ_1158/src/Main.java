// 백준 1158: 요세푸스 문제(실버 IV), https://www.acmicpc.net/problem/1158
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N, K, cnt = 1;
        Queue<Integer> queue = new LinkedList<>();
        Queue<Integer> answer = new LinkedList<>();

        // 입력
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        // 처리
        for(int i=1; i<=N; ++i)
            queue.add(i);

        while(!queue.isEmpty()){
            if(cnt == K){
                answer.add(queue.remove()); // queue에서 제거, answer에 추가
                cnt = 1;
                continue;
            }

            queue.add(queue.remove()); // queue head -> tail
            ++cnt;
        }

        // 출력
        bw.write("<");
        for(int i=0; i<N; ++i)
            bw.write(answer.remove() + ((i == N-1) ? ">\n" : ", "));

        br.close();
        bw.close();
    }

}
