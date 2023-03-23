#include <iostream>
#include <string>
using namespace std;
int cntArr[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill_n(cntArr, 10, 1);
	string N;
	int i, cnt = 1;
	cin >> N;
	while (N.length() > 0) {
		if (cntArr[N[0]-'0'] != 0) {
			--cntArr[N[0] - '0'];
			N.erase(N.begin());
		}
		else {
			if (N[0] == '6') {
				if (cntArr[9] != 0) {
					N.erase(N.begin());
					--cntArr[9];
				}
				else {
					++cnt;
					for (i = 0; i < 10; ++i)
						++cntArr[i];
				}
			}
			else if (N[0] == '9') {
				if (cntArr[6] != 0) {
					N.erase(N.begin());
					--cntArr[6];
				}
				else {
					++cnt;
					for (i = 0; i < 10; ++i)
						++cntArr[i];
				}
			}
			else {
				++cnt;
				for (i = 0; i < 10; ++i)
					++cntArr[i];
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}