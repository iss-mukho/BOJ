#include <iostream>
#include <string>
using namespace std;
int main() {
	string T;
	int cnt=0, s, i;
	cin >> T;
	s = T.size();
	for (i = 0; i < s; ++i) 
		if (T[i] == 'a' || T[i] == 'e' || T[i] == 'i' || T[i] == 'o' || T[i] == 'u')
			++cnt;
	cout << cnt << '\n';
	return 0;
}