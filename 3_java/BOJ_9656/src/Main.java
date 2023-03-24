// 백준 9656: 돌 게임 2(실버 IV), https://www.acmicpc.net/problem/9656
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        System.out.println((N % 2 == 0) ? "SK" : "CY");
    }
}
