// 백준 2961: 도영이가 만든 맛있는 음식(실버 II), https://www.acmicpc.net/problem/2961
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] so; // 신맛
    static int[] ni; // 쓴맛
    static boolean[] isUsed;
    static ArrayList<Integer> savedSo = new ArrayList<>();
    static ArrayList<Integer> savedNi = new ArrayList<>();
    static int answer = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // 입력
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        initArrays();

        for(int i=0; i<N; ++i){
            st = new StringTokenizer(br.readLine());

            so[i] = Integer.parseInt(st.nextToken());
            ni[i] = Integer.parseInt(st.nextToken());
        }

        // 처리
        for(int useCount=1; useCount<=N; ++useCount)
            getAnswer(0, 0, useCount);

        // 출력
        bw.write(answer + "\n");

        br.close();
        bw.close();
    }

    public static void initArrays(){
        so = new int[N];
        ni = new int[N];
        isUsed = new boolean[N];
    }

    public static int getSo(){
        int result = 1;
        for(var num: savedSo)
            result *= num;
        return result;
    }

    public static int getNi(){
        int result = 0;
        for(var num: savedNi)
            result += num;
        return result;
    }

    public static void getAnswer(int index, int count, int maxCount){
        if(count == maxCount){
            int tempAnswer = Math.abs(getSo() - getNi());
            answer = Integer.min(answer, tempAnswer);
            return;
        }

        for(int i=index; i<N; ++i){
            if(isUsed[i]) continue;

            isUsed[i] = true;
            savedSo.add(so[i]);
            savedNi.add(ni[i]);
            getAnswer(index+1, count+1, maxCount);
            isUsed[i] = false;
            savedSo.remove(savedSo.size()-1);
            savedNi.remove(savedNi.size()-1);
        }
    }

}
