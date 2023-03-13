// 백준 23883: 알고리즘 수업 - 선택 정렬 3(골드 IV), https://www.acmicpc.net/problem/23883
import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N;
    static int K;
    static int[] number;
    static int[] sortedNumber;
    static HashMap<Integer, Integer> map = new HashMap<>();
    static boolean isPrint = false;

    public static void main(String[] args) throws IOException {
        // 입력
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        number = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i)
            number[i] = Integer.parseInt(st.nextToken());

        // 처리 및 출력
        for(int i=0; i<N; ++i)
            map.put(number[i], i);

        sortedNumber = Arrays.copyOf(number, N);
        Arrays.sort(sortedNumber);

        /**
         * Before: Priority Queue를 사용해 시도 -> 반례 발견
         * After: Dictionary(HashMap)
         *
         *  number = 원본 배열
         *  sortedNumber = O(N log N)으로 정렬된 배열
         *  map = numberumber와 그 index를 저장한 hashMap
         *
         * 메커니즘
         *  1. 거꾸로 비교하며 number[i]가 정렬되어 있는지 확인
         *  2. 정렬되어 있지 않다면 교체가 진행됨
         *  3. 조건에 맞게 출력
         */
        for(int i=N-1; i>-1; --i){
            if(sortedNumber[i] == number[i]) continue;

            int []change = {number[i], sortedNumber[i]};

            swap(number, i, map.get(sortedNumber[i])); // number의 index와 sortedNumber의 index
            swap(map, change[0], change[1]);

            if (--K == 0){
                bw.write(change[0] + " " + change[1] + "\n");
                isPrint = true;
                break;
            }
        }

        if(!isPrint)
            bw.write("-1\n");

        br.close();
        bw.close();
    }

    // No call by value
    public static void swap(int []arr, int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    public static void swap(HashMap<Integer, Integer> map, int a, int b){
        int temp = map.get(a);
        map.put(a, map.get(b));
        map.put(b, temp);
    }
}