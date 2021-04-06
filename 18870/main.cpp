#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int input[1000001];
vector<int> comp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, x, i, j;
	cin >> N;
	for (i = 1;i <= N;++i) {
		cin >> x;
		input[i] = x;
		comp.push_back(x);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end()); // unique의 return 값은 유일한 원소들이 끝나고 첫번째 쓰레기 원소가 나오는 곳의 위치이다.
	for (i = 1;i <= N;++i)
		cout << lower_bound(comp.begin(), comp.end(), input[i]) - comp.begin() << ' '; // lower_bound() - .begin()은 해당 범위 안에서 value보다 작은 값들의 수를 반환한다.
	cout << '\n';
	return 0;
}