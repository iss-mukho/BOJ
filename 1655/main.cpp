#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> num;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i, mid, n;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> n;
		num.push_back(n);
		sort(num.begin(), num.end());
		mid = num.size() % 2 == 1 ? num.size() / 2 : num.size() / 2 - 1;
		cout << num[mid] << '\n';
	}
	return 0;
}