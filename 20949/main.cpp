#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b) {
	if (a.second > b.second)
		return true;
	else if (a.second == b.second) {
		if (a.first < b.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

vector<pair<int, double>> v;
int main() {
	int N, i, W, H;
	cin >> N;

	for (i = 1; i <= N; ++i) {
		cin >> W >> H;
		double PPI = sqrt(pow(W, 2) + pow(H, 2)) / 77;
		pair<int, double> temp(i, PPI);
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), cmp);

	for (i = 0; i < N; ++i)
		cout << v[i].first << '\n';

	return 0;
}