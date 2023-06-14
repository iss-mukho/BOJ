// 백준 1708: 블록 껍질(플래티넘 V), https://www.acmicpc.net/problem/1708
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct P {
	ll x, y;
	ll p, q;
	P(ll x = 0, ll y = 0) : x(x), y(y), p(0), q(p) {}
};

int N, x, y;
P points[100001];

int CCW(const P &a, const P &b, const P &c) {
	ll result = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
	if (result > 0) return 1;
	else if (result < 0) return -1;
	return 0;
}

ll DET(const P &a, const P &b) {
	return a.p * b.q - a.q * b.p;
}

bool angleSort(P &a, P &b) {
	if (a.p != 0 || a.q != 0 || b.p != 0 || b.q != 0) {
		if (DET(a, b) > 0) return true;
		if (DET(a, b) < 0) return false;
		return a.p * a.p + a.q * a.q < b.p * b.p + b.q * b.q;
	}

	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

void convexHull() {
	vector<int> stack;
	sort(points, points + N, angleSort);

	for (int i = 1; i < N; ++i) {
		points[i].p = points[i].x - points[0].x;
		points[i].q = points[i].y - points[0].y;
	}

	sort(points + 1, points + N, angleSort);

	int start, mid, end = 2;
	stack.push_back(0);
	stack.push_back(1);

	while (end != N) {
		while (stack.size() >= 2) {
			mid = stack.back();
			stack.pop_back();
			start = stack.back();

			if (CCW(points[start], points[mid], points[end]) > 0) {
				stack.push_back(mid);
				break;
			}
		}
		stack.push_back(end++);
	}

	cout << stack.size() << '\n';
}

void input() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		points[i] = P(x, y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	convexHull();

	return 0;
}
