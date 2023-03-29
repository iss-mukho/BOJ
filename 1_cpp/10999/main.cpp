// 백준 10999: 구간 합 구하기 2(플래티넘 IV), https://www.acmicpc.net/problem/10999
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAX = 1000001;

ll N, M, K, startIndex = 1, a, b, c, d;
ll numbers[MAX], tree[MAX * 4], lazy[MAX * 4];

void input() {
	scanf("%lld %lld %lld", &N, &M, &K);

	for (ll i = 1; i <= N; ++i)
		scanf("%lld", &numbers[i]);
}

ll init(ll start, ll end, ll node) {
	if (start == end) return tree[node] = numbers[start];

	ll mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void updateLazy(ll start, ll end, ll node) {
	if (!lazy[node]) return;

	tree[node] += (lazy[node] * (end - start + 1));
	if (start != end) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(ll start, ll end, ll left, ll right, ll number, ll node) {
	updateLazy(start, end, node);
	if (right < start || end < left) return;
	if (left <= start && end <= right) {
		tree[node] += (number * (end - start + 1));
		if (start != end) {
			lazy[node * 2] += number;
			lazy[node * 2 + 1] += number;
		}
		return;
	}

	ll mid = (start + end) / 2;
	update(start, mid, left, right, number, node * 2);
	update(mid + 1, end, left, right, number, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll getSum(ll start, ll end, ll left, ll right, ll node) {
	updateLazy(start, end, node);
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	ll mid = (start + end) / 2;
	return getSum(start, mid, left, right, node * 2) + getSum(mid + 1, end, left, right, node * 2 + 1);
}

int main() {
	input();

	init(1, N, 1);
	
	for (ll i = 0; i < M + K; ++i) {
		scanf("%lld", &a);

		if (a == 1) {
			scanf("%lld %lld %lld", &b, &c, &d);
			update(1, N, b, c, d, 1);
			continue;
		}
		scanf("%lld %lld", &b, &c);
		printf("%lld\n", getSum(1, N, b, c, 1));
	}

	return 0;
}
