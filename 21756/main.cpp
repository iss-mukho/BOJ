#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, output = 2;
	cin >> N;
	while (true) {
		if (output > N) {
			output /= 2;
			break;
		}
		output *= 2;
	}
	cout << output << '\n';
	return 0;
}