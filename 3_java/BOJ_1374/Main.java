// 백준 1374: 강의실(골드 V), https://www.acmicpc.net/problem/1374
import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static class lecture implements Comparable<lecture> {
        int num, start, end;

        public lecture(int num, int start, int end) {
            this.num = num;
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(lecture l){
            return this.start - l.start;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        // 시작시간 순으로 정렬
        PriorityQueue<lecture> L = new PriorityQueue<>();

        int N = Integer.parseInt(st.nextToken());
        for(int i=0; i<N; ++i){
            st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            L.add(new lecture(n, s, e));
        }

        // 종료 시간 순으로 방 정렬
        PriorityQueue<Integer> R = new PriorityQueue<>();
        R.add(L.poll().end);

        while(!L.isEmpty()){
            int rCnt = R.size();
            lecture cl = L.poll();
            boolean isPossible = false;

            for(int i=0; i<rCnt; ++i){
                // 현재 강의실에서 강의가 가능한가
                if(R.peek() <= cl.start){
                    R.poll(); // 현재 강의실에서 강의 제거
                    R.add(cl.end); // 다음 강의의 종료 시간 삽입
                    isPossible = true;
                    break;
                }
            }
            if(!isPossible) R.add(cl.end);
        }

        bw.write(R.size() + "\n");
        br.close();
        bw.close();
    }
}
