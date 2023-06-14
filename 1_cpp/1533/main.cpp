// 백준 1533: 길의 개수(플래티넘 III), https://www.acmicpc.net/problem/1533
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;
const int MOD = 1000003;

ll N, S, E, T;
mat A;
mat answer;

mat operator *(mat &a, mat &b) {
	mat result(5 * N + 1, vector<ll>(5 * N + 1));

	for (int i = 1; i <= 5 * N; i++) {
		for (int j = 1; j <= 5 * N; j++) {
			for (int k = 1; k <= 5 * N; k++) {
				result[i][j] += (a[i][k] * b[k][j]);
				result[i][j] %= MOD;
			}
		}
	}

	return result;
}

void matPow() {
	while (T) {
		if (T % 2) answer = answer * A;
		T /= 2;
		A = A * A;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S >> E >> T;
	
	A.assign(5 * N + 1, vector<ll>(5 * N + 1));
	answer.assign(5 * N + 1, vector<ll>(5 * N + 1));

	for (int i = 1; i <= N; ++i) {
		string s;
		cin >> s;

		for (int j = 0; j < (int)s.size(); ++j) 
			if (s[j] - '0' >= 1) A[i * 5][(j + 1) * 5 - (s[j] - '0' - 1)] = 1;
		for (int j = 1; j <= 4; ++j)
			A[(i - 1) * 5 + j][(i - 1) * 5 + j + 1] = 1;
	}

	for (int i = 1; i <= 5 * N; ++i) answer[i][i] = 1;
	matPow();

	cout << answer[5 * S][5 * E] << '\n';

	return 0;
}
