#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, string> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N, i;
	string juso, pw;
	cin >> M >> N;
	for (i = 0; i < M; ++i) {
		cin >> juso >> pw;
		pair<string, string> p(juso, pw);
		m.insert(p);
	}
	for (i = 0; i < N; ++i) {
		cin >> juso;
		cout << m[juso] << '\n';
	}
	return 0;
}