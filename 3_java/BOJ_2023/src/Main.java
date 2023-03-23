// 백준 2023: 신기한 소수(골드 V),https://www.acmicpc.net/problem/2023
import java.io.*;
import java.util.Scanner;

public class Main {

    static int N;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();

        checkPrimeNumber(2, 1);
        checkPrimeNumber(3, 1);
        checkPrimeNumber(5, 1);
        checkPrimeNumber(7, 1);
    }

    public static boolean isPrimeNumber(int number){
        if(number == 1) return false;

        // MAX 10000, 에라토스테네스의 체
        for(int i=2; i<Math.sqrt(number); ++i)
            if(number % i == 0)
                return false;
        return true;
    }

    public static void checkPrimeNumber(int number, int count){
        if(count == N){
            System.out.println(number);
            return;
        }

        for(int i=1; i<10; i+=2){
            if(i == 5) continue;

            int temp = number * 10 + i;
            if(!isPrimeNumber(temp)) continue;
            checkPrimeNumber(temp, count+1);
        }
    }
}
