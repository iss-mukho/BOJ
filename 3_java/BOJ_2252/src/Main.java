import java.util.*;
import java.io.*;

public class Main {
    public static int N, M, A, B;
    public static ArrayList<ArrayList<Integer>> student = new ArrayList<>();
    public static int[] indegree;
    public static ArrayList<Integer> answer = new ArrayList<>();

    public static void topologySort() {
        Queue<Integer> q = new LinkedList<>();

        for(int i = 1; i <= N; ++i)
            if(indegree[i] == 0) q.add(i);

        while(!q.isEmpty()) {
            int cur = q.poll();
            answer.add(cur);

            for(var next : student.get(cur))
                if(--indegree[next] == 0) q.add(next);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i = 0; i <= N; ++i) student.add(new ArrayList<>());
        indegree = new int[N + 1];

        for(int i = 0; i < M; ++i) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            student.get(A).add(B);
            ++indegree[B];
        }

        topologySort();

        for(var number : answer) bw.write(number + " ");
        bw.write("\n");

        bw.flush();
        br.close();
        bw.close();
    }
}
