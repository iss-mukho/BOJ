// 백준 2493: 탑(골드 V), https://www.acmicpc.net/problem/2493
import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N, maxIdx = 0;
        int []number; int []answer;
        Stack<Integer> stack = new Stack<>();

        // 입력 1
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        // 초기화
        number = new int[N + 1]; answer = new int[N + 1];

        // 입력 2
        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=N; ++i)
            number[i] = Integer.parseInt(st.nextToken());

        // 처리
        stack.add(0); // save dummy
        for(int i=1; i<=N; ++i) {
            // 바로 옆에 있는 탑이 현재 탑보다 낮은 경우
            while(number[stack.peek()] < number[i]){
                if(stack.peek() == 0) break; // 더미는 버리지 않습니다. 더미 살려
                stack.pop(); // 스택에 저장된 값들 중, 현재 위치의 탑보다 높이가 낮은 경우 제거
            }

            answer[i] = stack.peek(); // 수신 받는 탑의 위치 저장
            stack.add(i); // 스택에 현재 위치 추가
        }

        // 출력
        for(int i=1; i<=N; ++i)
            bw.write(answer[i] + " ");
        bw.write("\n");

        br.close();
        bw.close();
    }

}
