// 백준 1157: 단어 공부(브론즈 I), https://www.acmicpc.net/problem/1157
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static final int SIZE = 26;
    static int[] alphabet = new int [SIZE];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        String word = st.nextToken().toUpperCase();

        for(int i=0; i<word.length(); ++i)
            ++alphabet[(word.charAt(i) - 65)];

        int maxCount = -1;
        int maxIndex = -1;
        for(int i=0; i<SIZE; ++i){
            if(alphabet[i] <= maxCount) continue;

            maxIndex = i;
            maxCount = alphabet[i];
        }

        boolean isQuestionMark = false;
        for(int i=0; i<SIZE; ++i){
            if(i == maxIndex) continue;
            if(alphabet[i] != maxCount) continue;

            isQuestionMark = true;
            break;
        }

        bw.write((!isQuestionMark ? (char)(maxIndex + 65) : "?") + "\n");
        bw.flush();

        br.close();
        bw.close();
    }
}
