#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, i, pos, a, b;
	string tc;
	cin >> T;
	for (i = 0; i < T; ++i) {
		cin >> tc;
		pos = tc.find(",");
		a = stoi(tc.substr(0, pos));
		b = stoi(tc.substr(pos+1,tc.length()));
		cout << a + b << '\n';;
	}
	return 0;
}