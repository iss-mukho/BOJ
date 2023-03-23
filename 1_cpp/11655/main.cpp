#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string S;
	int len, i;
	getline(cin, S);
	len = S.size();
	for (i = 0; i < len; ++i) {
		if ((S[i] - 0 >= 65 && S[i] - 0 <= 90) || (S[i] - 0 >= 97 && S[i] - 0 <= 127)) {
			if ((S[i] - 0 >= 78 && S[i] - 0 <= 90) || (S[i] - 0 >= 110 && S[i] - 0 <= 122))
				cout << (char)(S[i] - 13);
			
			else
				cout << (char)(S[i] + 13);
		}
		else
			cout << S[i];
	}
	cout << '\n';
	return 0;
}