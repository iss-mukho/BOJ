// πÈ¡ÿ 2448: ∫∞ ¬Ô±‚ - 11(∞ÒµÂ IV), https://www.acmicpc.net/problem/2448
#include <iostream>
using namespace std;

int N;
char star[3072][6143];

void input() {
	cin >> N;
}

void init() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 2 * N - 1; ++j)
			star[i][j] = ' ';
}

void draw(int x, int y) {
	star[x][y] = '*';
	star[x + 1][y - 1] = star[x + 1][y + 1] = '*';
	for (int i = 0; i < 5; ++i) star[x + 2][y - 2 + i] = '*';
}

void run(int size, int x, int y) {
	if (size == 3) {
		draw(x, y);
		return;
	}
	
	run(size / 2, x, y);
	run(size / 2, x + (size / 2), y - (size / 2));
	run(size / 2, x + (size / 2), y + (size / 2));
}

void output() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 2 * N - 1; ++j)
			cout << star[i][j];
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	init();
	run(N, 0, N - 1);
	output();

	return 0;
}
