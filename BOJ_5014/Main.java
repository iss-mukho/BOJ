// 백준 5014: 스타트링크(실버 I), https://www.acmicpc.net/problem/5014
import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static class pii{
        int f;
        int c;

        pii(int f, int c){
            this.f = f;
            this.c = c;
        }
    }

    static int F, S, G, U, D, cnt = Integer.MAX_VALUE;
    static int[] floor;
    static boolean[] visited;
    static Queue<pii> q = new LinkedList();

    static void input(){
        F = sc.nextInt();
        S = sc.nextInt();
        G = sc.nextInt();
        U = sc.nextInt();
        D = sc.nextInt();
    }
    static void init(){
        floor = new int[F];
        visited = new boolean[F + 1];
    }

    static boolean inRange(int f){
        if(1 <= f && f <= F)
            return true;
        return false;
    }
    static void bfs(pii start) {
        q.add(start);

        while(!q.isEmpty()){
            int s = q.peek().f;
            int c = q.peek().c;
            q.poll();

            if(s == G){
                cnt = Math.min(cnt, c);
                visited[s] = false;
                continue;
            }
            if(visited[s]) continue;
            visited[s] = true;

            if(inRange(s + U) && !visited[s + U])
                q.add(new pii(s + U, c + 1));
            if(inRange(s - D) && !visited[s - D])
                q.add(new pii(s - D, c + 1));
        }
    }
    static void output(){
        if(cnt == Integer.MAX_VALUE)
            System.out.println("use the stairs");
        else
            System.out.println(cnt);
    }

    public static void main(String[] args){
        input();
        init();
        bfs(new pii(S, 0));
        output();
    }
}
