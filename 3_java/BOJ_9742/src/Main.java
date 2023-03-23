// 백준 19742: 순열(실버 III), https://www.acmicpc.net/problem/9742
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static String inputCase;
    static int index;
    static int permutationCount;
    static boolean []checked;
    static ArrayList<Character> output = new ArrayList<>();

    public static void main(String[] args) throws IOException {

        String input;
        while ((input = br.readLine()) != null) {
            String []temp = input.split(" ");

            inputCase = temp[0];
            index = Integer.parseInt(temp[1]);
            permutationCount = 0;
            checked = new boolean[index];

            if(index > getMaxIndex(inputCase)){
                print();
                continue;
            }
            back(0);
        }

        br.close();
        bw.close();
    }

    public static int getMaxIndex(String inputCase){
        int maxIndex = 1;
        int caseLength = inputCase.length();

        while(caseLength > 0)
            maxIndex *= caseLength--;

        return maxIndex;
    }

    public static void print() throws IOException {
        bw.write(inputCase + " " + index + " = ");
        if(output.isEmpty()){
            bw.write("No permutation\n");
            return;
        }
        for(var o: output)
            bw.write(o);
        bw.write("\n");
    }

    public static void back(int count) throws IOException {
        if(count == inputCase.length()){
            if(++permutationCount == index) print();
            return;
        }

        for(int i=0; i<inputCase.length(); ++i){
            if(checked[i]) continue;

            checked[i] = true;
            output.add(inputCase.charAt(i));
            back(count+1);
            checked[i] = false;
            output.remove(output.size()-1);
        }
    }
}
