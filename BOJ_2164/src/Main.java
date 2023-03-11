import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N;
        Queue<Integer> queue = new LinkedList<>();

        // 입력
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        // 처리
        for(int i=1; i<=N; ++i)
            queue.add(i);

        while(queue.size() > 1){
            queue.remove();
            queue.add(queue.remove());
        }

        // 출력
        bw.write(queue.peek() + "\n");

        br.close();
        bw.close();
    }

}
