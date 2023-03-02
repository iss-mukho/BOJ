// 백준 1275: 커피숍2(골드 I), https://www.acmicpc.net/problem/1275
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAX = 100000;
ll N, Q, x, y, a, b, startIdx, numbers[MAX], tree[MAX * 3 + 1];

void init() {
	startIdx = 1;
	while (startIdx <= N)
		startIdx *= 2;
	for (ll i = 0; i < N; ++i)
		tree[startIdx + i] = numbers[i];
	for (ll i = startIdx - 1; i > 0; --i)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void update(ll idx, ll diff) {
	while (idx > 0) {
		tree[idx] += diff;
		idx /= 2;
	}
}

ll getSum(ll left, ll right) {
	ll ans = 0;
	while (left <= right) {
		if (left % 2 == 1)
			ans += tree[left];
		if (right % 2 == 0)
			ans += tree[right];
		left = (left + 1) / 2;
		right = (right - 1) / 2;
	}
	return ans;
}

int main() {
	// 입력 1
	scanf("%lld %lld", &N, &Q);
	for (ll i = 0; i < N; ++i)
		scanf("%lld", &numbers[i]);

	// 트리 초기화
	init();

	// 입력 2, 출력 및 처리
	for (ll i = 0; i < Q; ++i) {
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if (x > y) swap(x, y);
		printf("%lld\n", getSum(startIdx + x - 1, startIdx + y - 1));
		update(startIdx + a - 1, b - tree[startIdx + a - 1]);
	}

	return 0;
}