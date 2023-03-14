// 백준 1759: 암호 만들기(골드 V), https://www.acmicpc.net/problem/1759
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int L;
    static int C;
    static ArrayList<String> alphabet = new ArrayList<>();
    static ArrayList<String> output = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        StringTokenizer st;

        // 입력
        st = new StringTokenizer(br.readLine());
        L = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<C; ++i)
            alphabet.add(st.nextToken());

        // 처리 및 출력
        Collections.sort(alphabet);
        back(0, 0);

        br.close();
        bw.close();
    }

    public static void print() throws IOException {
        for(var num: output)
            bw.write(num);
        bw.write("\n");
    }

    public static int getAeiouCount(){
        int cnt = 0;
        for(var o: output){
            if(    o.equals("a")
                || o.equals("e")
                || o.equals("i")
                || o.equals("o")
                || o.equals("u")) ++cnt;
        }
        return cnt;
    }

    public static void back(int count, int index) throws IOException {
        if(count == L){
            int aeiou = getAeiouCount();
            if(aeiou >= 1 && L-aeiou >= 2) print();
            return;
        }

        for(int i=index; i<C; ++i){
            output.add(alphabet.get(i));
            back(count+1, i+1);
            output.remove(output.size()-1);
        }
    }
}
