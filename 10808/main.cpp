#include <iostream>
#include <string>
using namespace std;
int counting[26] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string S;
	int i, s;
	cin >> S;
	s = S.size();
	for (i = 0; i < s; ++i) 
		++counting[S[i] - 'a'];
	for (i = 0; i < 26; ++i)
		cout << counting[i] << ' ';
	cout << '\n';
	return 0;
}