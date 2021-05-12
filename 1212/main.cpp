#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string N, save, temp;
	int len, i, j, t;
	cin >> N;
	len = N.size();
	for (i = 0; i < len; ++i) {
		temp = "";
		t = N[i] - '0';
		for (j = 0; j < 3; ++j) {
			temp += to_string(t % 2);
			t /= 2;
		}
		reverse(temp.begin(), temp.end());
		if (i == 0) 
			temp = to_string(stoi(temp));
		save += temp;
	}
	cout << save << '\n';
	return 0;
}