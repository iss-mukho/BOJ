// 백준 12100: 2048 (Easy)(골드 II), https://www.acmicpc.net/problem/12100
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, answer = 0;
    static int[][] board;
    static int[] movingCase = new int[5];
    static int[][] copyBoard;
    static boolean[][] visited;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        process();

        bw.flush();
        br.close();
        bw.close();
    }

    public static void input() throws IOException {
        N = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());

        board = new int[N][N];
        copyBoard = new int[N][N];
        visited = new boolean[N][N];

        for(int i=0; i<N; ++i){
            StringTokenizer line = new StringTokenizer(br.readLine());
            for(int j=0; j<N; ++j)
                board[i][j] = Integer.parseInt(line.nextToken());
        }
    }

    public static void process() throws IOException {
        setMovingCase(0);
        bw.write(answer + "\n");
    }

    public static void setMovingCase(int index){
        if(index == 5){
            setCopyBoard();
            initVisited();
            play();
            return;
        }

        for(int i=0; i<4; ++i){
            movingCase[index] = i;
            setMovingCase(index + 1);
        }
    }

    public static void setCopyBoard(){
        for(int i=0; i<N; ++i)
            System.arraycopy(board[i], 0, copyBoard[i], 0, N);
    }

    public static void initVisited(){
        for(int i=0; i<N; ++i)
            Arrays.fill(visited[i], false);
    }

    public static void play(){
        for(int direction: movingCase){
            if(direction == 1) moveUp();
            else if(direction == 2) moveDown();
            else if(direction == 3) moveLeft();
            else moveRight();
        }

        answer = Math.max(answer, getAnswer());
    }

    public static int getAnswer(){
        return Arrays.stream(copyBoard)
                .flatMapToInt(Arrays::stream)
                .max()
                .getAsInt();
    }

    public static void moveUp(){
        // Move
        for(int i=0; i<N-1; ++i){
            for(int j=0; j<N; ++j){
                boolean check = false;

                if(copyBoard[i][j] == 0){
                    int k = i + 1;

                    while(k <= N-1){
                        if(copyBoard[k][j] != 0){
                            check = true;
                            break;
                        }
                        ++k;
                    }

                    if(check){
                        copyBoard[i][j] = copyBoard[k][j];
                        copyBoard[k][j] = 0;
                    }
                }
            }
        }

        // Merge
        for(int i=0; i<N-1; ++i){
            for(int j=0; j<N; ++j){
                if(copyBoard[i][j] == copyBoard[i+1][j]){
                    copyBoard[i][j] *= 2;
                    copyBoard[i+1][j] = 0;
                }
            }
        }

        // Move 2
        for(int i=0; i<N-1; ++i){
            for(int j=0; j<N; ++j){
                boolean check = false;

                if(copyBoard[i][j] == 0){
                    int k = i + 1;

                    while(k < N){
                        if(copyBoard[k][j] != 0){
                            check = true;
                            break;
                        }
                        ++k;
                    }

                    if(check){
                        copyBoard[i][j] = copyBoard[k][j];
                        copyBoard[k][j] = 0;
                    }
                }
            }
        }
    }

    public static void moveDown(){
        // Move
        for(int i=N-1; i>0; --i){
            for(int j=0; j<N; ++j){
                boolean check = false;

                if(copyBoard[i][j] == 0){
                    int k = i - 1;

                    while(k >= 0){
                        if(copyBoard[k][j] != 0){
                            check = true;
                            break;
                        }
                        --k;
                    }

                    if(check){
                        copyBoard[i][j] = copyBoard[k][j];
                        copyBoard[k][j] = 0;
                    }
                }
            }
        }

        // Merge
        for(int i=N-1; i>0; --i){
            for(int j=0; j<N; ++j){
                if(copyBoard[i][j] == copyBoard[i-1][j]){
                    copyBoard[i][j] *= 2;
                    copyBoard[i-1][j] = 0;
                }
            }
        }

        // Move 2
        for(int i=N-1; i>0; --i){
            for(int j=0; j<N; ++j){
                boolean check = false;

                if(copyBoard[i][j] == 0){
                    int k = i - 1;

                    while(k >= 0){
                        if(copyBoard[k][j] != 0){
                            check = true;
                            break;
                        }
                        --k;
                    }

                    if(check){
                        copyBoard[i][j] = copyBoard[k][j];
                        copyBoard[k][j] = 0;
                    }
                }
            }
        }
    }

    public static void moveLeft(){
        // Move
        for(int i=0; i<N; ++i){
            for(int j=0; j<N-1; ++j){
                boolean check = false;

                if(copyBoard[i][j] == 0){
                    int k = j + 1;

                    while(k <= N-1){
                        if(copyBoard[i][k] != 0){
                            check = true;
                            break;
                        }
                        ++k;
                    }

                    if(check){
                        copyBoard[i][j] = copyBoard[i][k];
                        copyBoard[i][k] = 0;
                    }
                }
            }
        }

        // Merge
        for(int i=0; i<N; ++i){
            for(int j=0; j<N-1; ++j){
                if(copyBoard[i][j] == copyBoard[i][j+1]){
                    copyBoard[i][j] *= 2;
                    copyBoard[i][j+1] = 0;
                }
            }
        }

        // Move 2
        for(int i=0; i<N; ++i){
            for(int j=0; j<N-1; ++j){
                boolean check = false;

                if(copyBoard[i][j] == 0){
                    int k = j + 1;

                    while(k <= N-1){
                        if(copyBoard[i][k] != 0){
                            check = true;
                            break;
                        }
                        ++k;
                    }

                    if(check){
                        copyBoard[i][j] = copyBoard[i][k];
                        copyBoard[i][k] = 0;
                    }
                }
            }
        }
    }

    public static void moveRight(){
        // Move
        for(int i=0; i<N; ++i){
            for(int j=N-1; j>0; --j){
                boolean check = false;

                if(copyBoard[i][j] == 0){
                    int k = j - 1;

                    while(k >= 0){
                        if(copyBoard[i][k] != 0){
                            check = true;
                            break;
                        }
                        --k;
                    }

                    if(check){
                        copyBoard[i][j] = copyBoard[i][k];
                        copyBoard[i][k] = 0;
                    }
                }
            }
        }

        // Merge
        for(int i=0; i<N; ++i){
            for(int j=N-1; j>0; --j){
                if(copyBoard[i][j] == copyBoard[i][j-1]){
                    copyBoard[i][j] *= 2;
                    copyBoard[i][j-1] = 0;
                }
            }
        }

        // Move 2
        for(int i=0; i<N; ++i){
            for(int j=N-1; j>0; --j){
                boolean check = false;

                if(copyBoard[i][j] == 0){
                    int k = j - 1;

                    while(k >= 0){
                        if(copyBoard[i][k] != 0){
                            check = true;
                            break;
                        }
                        --k;
                    }

                    if(check){
                        copyBoard[i][j] = copyBoard[i][k];
                        copyBoard[i][k] = 0;
                    }
                }
            }
        }
    }
}
