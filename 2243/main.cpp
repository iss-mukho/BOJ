// 백준 2243: 사탕상자(플래티넘 V), https://www.acmicpc.net/problem/2243
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 1000001;

int n, A, B, C;
int tree[MAX * 4]; // no index tree, segment tree.

// Segment Tree Practice
void update(int index, int target, int diff, int start, int end) {
	if (target < start || end < target) return;
	tree[index] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(index * 2, target, diff, start, mid);
	update(index * 2 + 1, target, diff, mid + 1, end);
}
int getRank(int index, int target, int start, int end) {
	if (start == end) return start;
	int mid = (start + end) / 2;
	if (target <= tree[index * 2]) return getRank(index * 2, target, start, mid);
	else return getRank(index * 2 + 1, target - tree[index * 2], mid + 1, end);
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d ", &A);
		if (A == 1) {
			scanf("%d", &B);
			int candy = getRank(1, B, 1, MAX); // 위치 구해서 출력
			printf("%d\n", candy);
			update(1, candy, -1, 1, MAX); // 1개를 꺼냈음
		}
		else {
			scanf("%d %d", &B, &C);
			update(1, B, C, 1, MAX); // B에 1개를 추가했음
		}
	}

	return 0;
}