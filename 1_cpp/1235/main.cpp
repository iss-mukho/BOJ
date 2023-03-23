#include <iostream>
#include <string>
using namespace std;
string stuNum[1000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, len, i, j, cnt = 1;
	string tempA, tempB;
	cin >> N;
	for (i = 0; i < N; ++i)
		cin >> stuNum[i];
	len = stuNum[0].length();
	for (i = 0; i < N - 1; ++i) {
		tempA = stuNum[i].substr(len - cnt, cnt);
		for (j = i + 1; j < N; ++j) {
			tempB = stuNum[j].substr(len - cnt, cnt);
			if (tempA == tempB) {
				++cnt;
				i = -1;
				break;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}