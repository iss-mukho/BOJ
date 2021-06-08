#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string S;
	int len, i, cnt = 1;
	cin >> S;
	len = S.length();
	for (i = 0; i < len; ++i)
		if (S[i] == ',')
			++cnt;
	cout << cnt << '\n';
	return 0;
}