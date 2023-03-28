import java.util.Scanner;

// 백준 10820: 문자열 분석(브론즈 II), https://www.acmicpc.net/problem/10820
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String inputString;

        while(true){
            try{
                inputString = sc.nextLine();

                int lowerCount = 0;
                int upperCount = 0;
                int numberCount = 0;
                int spaceCount = 0;

                for(int i=0; i<inputString.length(); ++i){
                    var s = inputString.charAt(i);

                    if('a' - 97 <= s - 97 && s - 97 <= 'z' - 97){
                        ++lowerCount;
                        continue;
                    }
                    if('A' - 65 <= s - 65 && s - 65 <= 'z' - 65){
                        ++upperCount;
                        continue;
                    }
                    if('0' - '0' <= s - '0' && s - '0' <= '9' - '0'){
                        ++numberCount;
                        continue;
                    }
                    if(s == ' ') ++spaceCount;
                }

                System.out.println(String.format("%d %d %d %d", lowerCount, upperCount, numberCount, spaceCount));

            } catch(Exception e){
                break;
            }
        }
    }
}
