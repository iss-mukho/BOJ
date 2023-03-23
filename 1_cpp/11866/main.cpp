#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int main() {
	int N, K, i;
 	cin >> N >> K;
	for (i = 1; i <= N; ++i)
		q.push(i);
	cout << '<';
	while (!q.empty()) {
		for (i = 0; i < K - 1; ++i) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (!q.empty())
			cout << ", ";
	}
	cout << ">\n";
	return 0;
}