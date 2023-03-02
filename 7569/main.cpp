// 백준 7569: 토마토(골드 V), https://www.acmicpc.net/problem/7569
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
const int MAX = 101;

int boxes[MAX][MAX][MAX], visited[MAX][MAX][MAX]; // [z][x][y]
int M, N, H, answer = 0;// 가로, 세로, 상자의 수

// U, D, L, R, up, down
int dx[6] = { +0, +0, -1, +1, +0, +0 };
int dy[6] = { -1, +1, +0, +0, +0, +0 };
int dz[6] = { +0, +0, +0, +0, -1, +1 };
bool inRange(int x, int y, int z) {
    if (0 <= x && x < N && 0 <= y && y < M && 0 <= z && z < H)
        return true;
    return false;
}

void getAnswer() {
    for (int k = 0; k < H; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                answer = max(answer, boxes[k][i][j]);
}

void BFS(ppi start) {
    deque<ppi> dq;
    dq.push_back(start);
    visited[start.second][start.first.first][start.first.second] = true;

    while (!dq.empty()) {
        int cx = dq.front().first.first, cy = dq.front().first.second, cz = dq.front().second;
        dq.pop_front();

        // U, D, L, R, up, down
        for (int i = 0; i < 6; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i], nz = cz + dz[i];

            if (!inRange(nx, ny, nz)) continue;
            if (boxes[nz][nx][ny] == -1) continue;
            if (boxes[nz][nx][ny] != 0 && boxes[nz][nx][ny] <= boxes[cz][cx][cy] + 1) continue;

            boxes[nz][nx][ny] = boxes[cz][cx][cy] + 1;
            visited[nz][nx][ny] = true;
            dq.push_back(ppi(pii(nx, ny), nz));
        }
    }
}

bool checkAllClear() {
    for (int k = 0; k < H; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (boxes[k][i][j] == -1) continue;
                if (boxes[k][i][j] == 0) return false;
            }
        }
    }
    return true;
}

int main() {
    // 입력
    scanf("%d %d %d", &M, &N, &H);

    for (int k = 0; k < H; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                scanf("%d", &boxes[k][i][j]);

    // 처리 및 출력
    if (checkAllClear()) printf("%d\n", 0);
    else {
        for (int k = 0; k < H; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < M; ++j)
                    if (boxes[k][i][j] == 1 && !visited[k][i][j])
                        BFS(ppi(pii(i, j), k));
        getAnswer();
        if (!checkAllClear()) printf("%d\n", -1);
        else printf("%d\n", answer - 1);
    }

    return 0;
}