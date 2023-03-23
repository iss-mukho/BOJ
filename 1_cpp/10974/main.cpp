#include <iostream>
#include <vector>
using namespace std;
void backtracking(int n);
int check[9] = { 0, };
vector<int> output;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	backtracking(N);
	return 0;
}
void backtracking(int n) {
	int i;
	if (output.size() == n) {
		for (i = 0; i < n; ++i)
			cout << output[i] << ' ';
		cout << '\n';
	}
	for (i = 1; i <= n; ++i) {
		if (!check[i]) {
			check[i] = 1;
			output.push_back(i);
			backtracking(n);
			check[i] = 0;
			output.pop_back();
		}
	}
}