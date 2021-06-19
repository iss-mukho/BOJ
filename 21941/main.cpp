#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int dp[101];
map<string, int> input;
map<string, int> input_len;
int dfs(int idx, string in);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill_n(dp, 101, -1);
	string S, ts;
	int M, i, score = 0, ti;
	
	// 입력
	cin >> S;
	cin >> M;
	for (i = 0; i < M; ++i) {
		cin >> ts >> ti;
		input.insert(make_pair(ts, ti));
		input_len.insert(make_pair(ts, ts.length()));
	}	

	// 출력
	cout << dfs(0, S) << '\n';
	return 0;
}

int dfs(int idx, string in) {
	if (idx >= in.length())
		return 0;
	if (dp[idx] != -1)
		return dp[idx];

	int max_value = 0, i, j, ti, tsl;
	map<string, int>::iterator iter1 = input.begin();
	map<string, int>::iterator iter2 = input_len.begin();
	for (i = 0; i < input.size(); ++i) {
		ti = (*iter1).second; tsl = (*iter2).second;

		if (idx + tsl - 1 < in.length()) {
			for (j = 0; j < tsl; ++j) {
				if (in[j + idx] != (*iter1).first[j])
					break;
				else
					max_value = max(max_value, ti + dfs(idx + tsl, in));
			}
		}

		++iter1; ++iter2;
	}

	max_value = max(max_value, 1 + dfs(idx + 1, in));
	dp[idx] = max_value;
	return dp[idx];
}