#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int main() {
	int N, i;
	cin >> N;
	for (i = 1; i <= N; ++i)
		q.push(i);
	while (q.size() > 1) {
		q.pop();
		if (q.size() == 1)
			break;
		q.push(q.front());
		q.pop();
		q.pop();
		if (q.size() == 1)
			break;
		q.push(q.front());
		q.pop();
	}
	cout << q.front() << '\n';
	return 0;
}