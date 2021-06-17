#include <iostream>
#include <queue>
using namespace std;
struct student {
	int country;
	int studentNum;
	int score;
	student(int a, int b, int c) :country(a), studentNum(b), score(c) {};
};
struct cmp{
	bool operator()(student a, student b) {
		return a.score < b.score;
	}
};
priority_queue<student, vector<student>, cmp> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, i, c, sn, s, cnt = 1, output = 0;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> c >> sn >> s;
		pq.push(student(c, sn, s));
	}
	c = 0;
	for (i = 0; i < N; ++i) {
		student temp = pq.top(); pq.pop();		
		if (c == temp.country) {
			if (cnt == 2)
				continue;
			++cnt;
		}
		c = temp.country;
		sn = temp.studentNum;
		cout << c << ' ' << sn << '\n';

		++output;
		if (output == 3)
			break;
	}
	return 0;
}