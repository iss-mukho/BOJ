// Thanks to: https://kangminjun.tistory.com/entry/BOJ-11437%EB%B2%88-LCA
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50001; // 노드 번호는 1~N. index 0은 사용하지 않음
int N, M, a, b, parent[MAX], depth[MAX];
bool visited[MAX];
vector<int> adj[MAX]; // 정점 간의 연결관계 저장

void calcTree(int before, int current, int cnt) {
	parent[current] = before;
	depth[current] = cnt;
	for (auto next : adj[current]) {
		if (visited[next])
			continue;
		visited[next] = true;
		calcTree(current, next, cnt + 1);
	}
}
int LCA(int a, int b) {
	if (depth[a] > depth[b]) // depth가 작은 것이 앞에
		swap(a, b);

	if (a == b) // 같은 노드 탐색
		return a;
	if (parent[a] == parent[b]) // 조상 노드가 같다
		return parent[a];

	if (a == 1 || b == 1) // 비교 대상 중 root 노드가 있다
		return 1;

	if (depth[a] == depth[b]) // depth가 같으면 조상을 검색
		return LCA(parent[a], parent[b]);
	else
		return LCA(a, parent[b]); // depth가 다르면, depth가 깊은 쪽의 조상과 비교
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력1: 정점 관계
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		cin >> a >> b;

		// 두 노드는 연결되어 있다.
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// 모든 간선을 입력받기 전까지는 누가 부모이고 누가 자식인지 판단할 수 없다.

	// 처리: get depth
	// 고민: depth를 어떻게 구하는가?
	visited[1] = true; // "루트는 1번이다.""루트는 1번이다.""루트는 1번이다.""루트는 1번이다."
	calcTree(0, 1, 0);

	// 입력2
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		cout << LCA(a, b) << '\n'; // 바로 출력
	}

	return 0;
}