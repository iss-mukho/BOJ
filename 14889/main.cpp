#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int team[21][21];
int min_ = 100;
vector<int> start;
vector<int> link;
int N, a, b;
void calc(int idx);
int main() {
	int i, j;
	cin >> N;
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= N; ++j)
			cin >> team[i][j];
	calc(1);
	cout << min_ << '\n';
	return 0;
}
void calc(int idx){
	if (idx == N+1) {
		if (start.size() == N / 2 && link.size() == N / 2) {
			int s=0, l=0;
			for (a = 0; a < N / 2; ++a) {
				for (b = a+1; b < N / 2; ++b) {
					s += team[start[a]][start[b]] + team[start[b]][start[a]];
					l += team[link[a]][link[b]] + team[link[b]][link[a]];
				}
			}
			min_ = min(min_, abs(s - l));
		}
		return;
	}
	start.push_back(idx);
	calc(idx + 1);
	start.pop_back();
	link.push_back(idx);
	calc(idx + 1);
	link.pop_back();
}



