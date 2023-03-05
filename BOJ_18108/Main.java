// 백준 10108: 1998년생인 내가 태국에서는 2541년생?!(브론즈 V), https://www.acmicpc.net/problem/18108
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int y;

    public static void main(String[] args) throws IOException {
        y = Integer.parseInt(br.readLine());
        System.out.println(y - 543);
    }
}
