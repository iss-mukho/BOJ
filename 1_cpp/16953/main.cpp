#include <iostream>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
const int MAX = 1000000001;

ll A, B;
map<ll, int> number;
queue<int> q;

void process(int cur, ll nextNum) {
	if (nextNum > B) return;

	if (number.find(nextNum) != number.end())
		number[nextNum] = min(number[cur] + 1, number[nextNum]);
	else
		number[nextNum] = number[cur] + 1;
	
	q.push(nextNum);
}

void bfs(int start) {
	q.push(start);
	number[start] = 1;

	while (!q.empty()) {
		ll cur = q.front();
		q.pop();

		if (cur == B) break;

		process(cur, cur * 10 + 1);
		process(cur, cur * 2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;

	bfs(A);

	cout << (number.find(B) == number.end() ? -1 : number[B]) << '\n';

	return 0;
}