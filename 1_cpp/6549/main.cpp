// 백준 6549: 히스토리에서 가장 큰 직사각형(플래티넘 V), https://www.acmicpc.net/problem/6549
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = 2100000000;
ll n, answer, number[100001], segmentTree[1000001];

ll makeTree(ll n, ll s, ll e) {
	if (s == e) return segmentTree[n] = s;
	
	ll m = (s + e) / 2;
	ll l = makeTree(2 * n, s, m);
	ll r = makeTree(2 * n + 1, m + 1, e);

	return segmentTree[n] = number[l] < number[r] ? l : r;
}

ll query(ll n, ll s, ll e, ll l, ll r) {
	if (e < l || r < s) return INF;
	if (l <= s && e <= r) return segmentTree[n];

	ll m = (s + e) / 2;
	ll left = query(2 * n, s, m, l ,r);
	ll right = query(2 * n + 1, m + 1, e, l, r);

	if (left == INF) return right;
	if (right == INF) return left;
	return segmentTree[n] = number[left] < number[right] ? left : right;
}

void process(ll l, ll r) {
	if (l > r) return;

	ll i = query(1, 0, n - 1, l, r);
	answer = max(answer, number[i] * (r - l + 1));

	process(l, i - 1);
	process(i + 1, r);
}

int main() {
	while (1) {
		answer = 0;
		scanf("%lld", &n);

		if (!n) break;
		for (int i = 0; i < n; ++i) scanf("%lld", &number[i]);
		
		makeTree(1, 0, n - 1);
		process(0, n - 1);

		printf("%lld\n", answer);
	}

	return 0;
}
