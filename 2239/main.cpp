#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

char inp[11];
int sudoku[9][9];
int zeroCount = 0;
vector<pair<int, int>> zero;

vector<int> getNumbers(int x, int y) {
	vector<int> numbers;
	int checked[10];
	for (int i = 1; i < 10; i++)
		checked[i] = 1;

	for (int i = 0; i < 9; i++) {
		if (checked[sudoku[x][i]] == 1)
			checked[sudoku[x][i]] = 0;
		if (checked[sudoku[i][y]] == 1)
			checked[sudoku[i][y]] = 0;
	}

	x = (x / 3) * 3;
	y = (y / 3) * 3;
	for (int i = x; i < x + 3; i++)
		for (int j = y; j < y + 3; j++)
			if (checked[sudoku[i][j]] == 1)
				checked[sudoku[i][j]] = 0;

	for (int i = 1; i < 10; i++)
		if (checked[i] == 1)
			numbers.push_back(i);

	return numbers;
}

void back(int cnt) {
	if (cnt == zeroCount) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d", sudoku[i][j]);
			printf("\n");
		}
		exit(0);
	}

	int x = zero[cnt].first;
	int y = zero[cnt].second;
	vector<int> numbers = getNumbers(x, y);

	for (auto number : numbers) {
		sudoku[x][y] = number;
		back(cnt + 1);
		sudoku[x][y] = 0;
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%s", &inp);
		for (int j = 0; j < 9; j++)
			sudoku[i][j] = inp[j] - '0';
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == 0) {
				zero.push_back(make_pair(i, j));
				zeroCount++;
			}
		}
	}
		
	back(0);

	return 0;
}