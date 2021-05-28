#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int row[50] = { 0, };
	int col[50] = { 0, };
	string input;
	int N, M, i, j, r = 0, c = 0, output;
	cin >> N >> M;
	for (i = 0; i < N; ++i) {
		cin >> input;
		for (j = 0; j < M; ++j) {
			if (input[j] == 'X') {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	for (i = 0; i < N; ++i)
		if (!row[i])
			++r;
	for (j = 0; j < M; ++j)
		if (!col[j])
			++c;
	output = (r > c) ? r : c;
	cout << output << '\n';
	return 0;
}