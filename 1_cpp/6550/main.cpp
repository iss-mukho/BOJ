// 백준 6550: 부분 문자열(실버 V)
#include <iostream>
#include <string>
using namespace std;

const int MAX = 100000;
int idx, cnt;
string s, t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> s >> t) {
		idx = 0;
		for (int i = 0; i < t.length(); ++i)
			if (s[idx] == t[i]) ++idx;
		
		if (idx == s.length()) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}