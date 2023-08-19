#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 100000;

int game[MAX][3], prefixSum[MAX][3];
int N, maxNum, minNum;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 3; ++j)
			scanf("%d", &game[i][j]);

	for (int i = 0; i < 3; ++i)
		prefixSum[0][i] = game[0][i];

	for (int i = 1; i < N; ++i) {
		prefixSum[i][0] = game[i][0] + *max_element(prefixSum[i - 1], prefixSum[i - 1] + 2);
		prefixSum[i][1] = game[i][1] + *max_element(prefixSum[i - 1], prefixSum[i - 1] + 3);
		prefixSum[i][2] = game[i][2] + *max_element(prefixSum[i - 1] + 1, prefixSum[i - 1] + 3);
	}
	maxNum = *max_element(prefixSum[N - 1], prefixSum[N - 1] + 3);

	for (int i = 1; i < N; ++i) {
		prefixSum[i][0] = game[i][0] + *min_element(prefixSum[i - 1], prefixSum[i - 1] + 2);
		prefixSum[i][1] = game[i][1] + *min_element(prefixSum[i - 1], prefixSum[i - 1] + 3);
		prefixSum[i][2] = game[i][2] + *min_element(prefixSum[i - 1] + 1, prefixSum[i - 1] + 3);
	}
	minNum = *min_element(prefixSum[N - 1], prefixSum[N - 1] + 3);

	printf("%d %d", maxNum, minNum);
	
	return 0;
}