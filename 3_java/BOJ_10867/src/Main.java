// 백준 10867: 중복 빼고 정렬하기(실버 V), https://www.acmicpc.net/problem/10867
import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N;
    static Integer[] numbers;
    static ArrayList<Integer> answer = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        input();
        process();
        output();

        br.close();
        bw.close();
    }

    public static void input() throws IOException {
        N = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());
        numbers = new Integer[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i)
            numbers[i] = Integer.parseInt(st.nextToken());
    }

    public static void process() {
        Set<Integer> set = new HashSet<>(Arrays.asList(numbers));

        for(var number: set)
            answer.add(number);
        Collections.sort(answer);
    }

    public static void output() throws IOException {
        for(var number: answer)
            bw.write(number + " ");
        bw.write("\n");
        bw.flush();
    }
}
