// 백준 11382: 꼬마 정민(브론즈 V), https://www.acmicpc.net/problem/11382
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static String[] numbers = new String[3];
    static long sum;

    public static void main(String[] args) throws IOException {
        numbers = br.readLine().split(" ");
        for(int i=0; i<3; ++i)
            sum += Long.parseLong(numbers[i]);

        System.out.println(sum);
    }
}
