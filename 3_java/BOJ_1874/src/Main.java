// 백준 1874: 스택 수열(실버 II), https://www.acmicpc.net/problem/1874
import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n;
        int []number; // 입력된 수열
        Stack<Integer> stack = new Stack<>(); // 스택
        String []answer; // 필요한 연산

        // 입력 1: n
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        // 초기화
        number = new int[n]; answer = new String[n*2];

        // 입력 2: 수열
        for(int i=0; i<n; ++i){
            st = new StringTokenizer(br.readLine());
            number[i] = Integer.parseInt(st.nextToken());
        }

        /**
         * num = 오름차순으로 스택에 넣을 숫자
         * nIdx = 수열(number) index
         * aIdx = 정답(answer) index
         */
        int num = 1; int nIdx = 0; int aIdx = 0;
        // 처리 1
        while(num <= n){
            // 숫자를 수열에 넣음
            if(stack.isEmpty() || stack.peek() != number[nIdx]){
                stack.push(num);
                answer[aIdx++] = "+";
                ++num;
            }

            // 스택의 제일 위에 있는 숫자가 수열의 순서에 맞다면
            if(stack.peek() == number[nIdx]){
                stack.pop();
                answer[aIdx++] = "-";
                ++nIdx;
            }
        }

        // 스택에 남은 숫자들이 있다면 마무리 연산
        while(!stack.isEmpty()){
            // 단, 수열의 순서와 맞지 않다면 연산하지 않음
            if(stack.peek() != number[nIdx]) break;

            stack.pop();
            answer[aIdx++] = "-";
            ++nIdx;
        }

        // 출력
        if(!stack.isEmpty())
            bw.write("NO" + "\n");
        else
            for(int i=0; i<aIdx; ++i)
                bw.write(answer[i] + "\n");

        br.close();
        bw.close();
    }

}
