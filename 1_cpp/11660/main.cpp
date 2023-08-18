#include <iostream>
using namespace std;

const int MAX = 1025;

int table[MAX][MAX], prefixSum[MAX][MAX];
int N, M, a1, b1, a2, b2;

void setPrefixSum() {
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			prefixSum[i][j] = table[i][j] - prefixSum[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1];
}

int process() {
	return prefixSum[a2][b2] + prefixSum[a1 - 1][b1 - 1] - prefixSum[a2][b1 - 1] - prefixSum[a1 - 1][b2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> table[i][j];

	setPrefixSum();

	for (int t = 0; t < M; ++t) {
		cin >> a1 >> b1 >> a2 >> b2;
		cout << process() << '\n';
	}

	return 0;
}