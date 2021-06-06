#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<int> q;
	int N, i, temp;
	cin >> N;
	for (i = 1; i <= N; ++i) {
		q.push(i);
	}
	while (q.size()>1) {
		cout << q.front() << ' ';
		q.pop();
		if (q.size() == 1)
			break;
		q.push(q.front());
		q.pop();
	}
	cout << q.front() << '\n';
	q.pop();
	return 0;
}