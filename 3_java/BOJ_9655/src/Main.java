// 백준 9655: 돌 게임(실버 V), https://www.acmicpc.net/problem/9655
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        System.out.println((N % 2 == 1) ? "SK" : "CY");
    }
}
