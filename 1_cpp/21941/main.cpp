#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct mukho {
	int score;
	int len;
};

string S; int N;
unordered_map<string, mukho> input;
string in[100];
int dp[1001];
int dfs(int idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int M, i, X, temp;
	string A;

	// 입력
	cin >> S;
	cin >> M;
	N = S.length();
	fill_n(dp, N+1, -1);
	for (i = 0; i < M; ++i) {
		cin >> A >> X;
		temp = A.length(); mukho t = { X, temp };
		input[A] = t; in[i] = A;
	}		

	// 출력
	cout << dfs(0) << '\n';
	return 0;
}

int dfs(int idx) {
	if (idx >= N)
		return 0;
	if (dp[idx] != -1)
		return dp[idx];

	int i, score, len, max_value = 0;

	for (string str: in) {
		score = input[str].score; len = input[str].len;

		if (idx + len - 1 < N) {
			for (i = 0; i < len; ++i) {
				if (S[i + idx] != str[i])
					break;
				else
					max_value = max(max_value, score + dfs(idx + len));
			}
		}
	}

	max_value = max(max_value, 1 + dfs(idx + 1));
	dp[idx] = max_value;
	return dp[idx];
}