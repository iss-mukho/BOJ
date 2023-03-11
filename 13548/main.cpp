// 백준 13548: 수열과 쿼리 6(플래티넘 I), https://www.acmicpc.net/submit/13548
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 100000;

// 구조체 연습
struct S {
	int x, y, num, ans;
} Q[MAX+1];

int N, M, A[MAX+1], sn, s, e, cMax, c[MAX+1], co[MAX+1];

// 정렬 기준
bool cmp1(S a, S b) {
	if (a.x / sn == b.x / sn) return a.y < b.y;
	return a.x / sn < b.x / sn;
}
bool cmp2(S a, S b) {
	return a.num < b.num;
}

// mo's algorithm
void up(int idx) {
	--co[c[idx]];
	if (c[idx] == cMax) ++cMax;
	++c[idx];
	++co[c[idx]];
}
void down(int idx) {
	--co[c[idx]];
	if (co[cMax] == 0) --cMax;
	--c[idx];
	++co[c[idx]];
}

int main() {
	// 입력
	scanf("%d", &N);
	sn = sqrt(N) + 1;

	for (int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);

	scanf("%d", &M);
	for (int i = 1; i <= M; ++i) {
		scanf("%d %d", &Q[i].x, &Q[i].y);
		Q[i].num = i;
	}

	// 처리
	co[0] = MAX;
	sort(Q + 1, Q + M + 1, cmp1);
	for (int i = Q[1].x; i <= Q[1].y; ++i)
		up(A[i]);

	s = Q[1].x; e = Q[1].y; Q[1].ans = cMax;
	for (int i = 2; i <= M; ++i) {
		while (e < Q[i].y) up(A[++e]);
		while (s > Q[i].x) up(A[--s]);
		while (e > Q[i].y) down(A[e--]);
		while (s < Q[i].x) down(A[s++]);
		Q[i].ans = cMax;
	}

	// 출력
	sort(Q + 1, Q + M + 1, cmp2);
	for (int i = 1; i <= M; ++i)
		printf("%d\n", Q[i].ans);

	return 0;
}