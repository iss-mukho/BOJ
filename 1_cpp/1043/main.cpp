#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 51;

int parent[MAX];
vector<int> v[MAX];
int N, M, T, t, P, p, answer = 0;

void init() {
	for (int i = 1; i <= N; ++i)
		parent[i] = i;
}

int findParent(int x) {
	if (parent[x] != x)
		parent[x] = findParent(parent[x]);
	return parent[x];
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	// 입력
	scanf("%d %d", &N, &M);
	init();

	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d", &t);
		parent[t] = 0;
	}
	
	for (int i = 1; i <= M; ++i) {
		scanf("%d", &P);
		for (int j = 0; j < P; ++j) {
			scanf("%d", &p);
			v[i].push_back(p);
		}

		// 처리
		sort(v[i].begin(), v[i].end());

		int front = v[i][0];
		for (int j = 1; j < P; ++j) {
			int num = v[i][j];

			if (findParent(front) == findParent(num)) continue;
			unionParent(front, num);
		}
	}
	
	for (int i = 1; i <= M; ++i) {
		bool jimin = true;

		for (int num : v[i]) {
			if (findParent(num) == 0) {
				jimin = false;
				break;
			}
		}

		if (jimin) ++answer;
	}

	// 출력
	printf("%d\n", answer);

	return 0;
}