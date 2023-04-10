// πÈ¡ÿ 2342: Dance Dance Revolution(∞ÒµÂ III), https://www.acmicpc.net/problem/2342
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000;

int n;
vector<int> v;
int dp[MAX][5][5];

int getPower(int s, int e) {
	if (s == e) return 1;
	if (s == 0) return 2;
	if (abs(s - e) % 2 == 0) return 4;
	return 3;
}

int calcPower(int N, int L, int R) {
	if (N >= v.size()) return 0;
	if (dp[N][L][R] != -1) return dp[N][L][R];

	dp[N][L][R] = min(calcPower(N + 1, v[N], R) + getPower(L, v[N]), calcPower(N + 1, L, v[N]) + getPower(R, v[N]));
	return dp[N][L][R];
}

int main() {
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < 5; ++j)
			for (int k = 0; k < 5; ++k)
				dp[i][j][k] = -1;

	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		
		v.push_back(n);
	}

	printf("%d\n", calcPower(0, 0, 0));
	
	return 0;
}
