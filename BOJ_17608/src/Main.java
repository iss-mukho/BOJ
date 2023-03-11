// 백준 17608: 막대기(브론즈 II), https://www.acmicpc.net/problem/17608
import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N, num, top, cnt = 1;
        Stack<Integer> stack = new Stack<>();

        // 입력
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        for(int i=0; i<N; ++i){
            st = new StringTokenizer(br.readLine());
            stack.add(Integer.parseInt(st.nextToken()));
        }

        // 처리
        top = stack.pop();
        while(!stack.isEmpty()){
            int next = stack.pop();

            if(top >= next) continue;
            ++cnt;
            top = next;
        }

        // 출력
        bw.write(cnt + "\n");

        br.close();
        bw.close();
    }

}
