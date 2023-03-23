// 백준 15649: N과 M (1)(실버 III), https://www.acmicpc.net/problem/15649
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N;
    static int M;
    static boolean []checked = new boolean[9];
    static ArrayList<Integer> output = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        StringTokenizer st;

        // 입력
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // 처리 및 출력
        back(0);

        br.close();
        bw.close();
    }

    public static void print() throws IOException {
        for(var num: output)
            bw.write(num + "\n");
    }

    public static void back(int count) throws IOException {
        if(count == M){
            print();
            return;
        }

        for(int i=1; i<=N; ++i){
            if(checked[i]) continue;

            checked[i] = true;
            output.add(i);
            back(count+1);
            checked[i] = false;
            output.remove(output.size()-1);
        }
    }
}
