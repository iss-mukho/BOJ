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
	comp.erase(unique(comp.begin(), comp.end()), comp.end()); // unique�� return ���� ������ ���ҵ��� ������ ù��° ������ ���Ұ� ������ ���� ��ġ�̴�.
	for (i = 1;i <= N;++i)
		cout << lower_bound(comp.begin(), comp.end(), input[i]) - comp.begin() << ' '; // lower_bound() - .begin()�� �ش� ���� �ȿ��� value���� ���� ������ ���� ��ȯ�Ѵ�.
	cout << '\n';
	return 0;
}