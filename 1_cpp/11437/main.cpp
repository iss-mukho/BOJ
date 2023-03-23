// Thanks to: https://kangminjun.tistory.com/entry/BOJ-11437%EB%B2%88-LCA
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50001; // ��� ��ȣ�� 1~N. index 0�� ������� ����
int N, M, a, b, parent[MAX], depth[MAX];
bool visited[MAX];
vector<int> adj[MAX]; // ���� ���� ������� ����

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
	if (depth[a] > depth[b]) // depth�� ���� ���� �տ�
		swap(a, b);

	if (a == b) // ���� ��� Ž��
		return a;
	if (parent[a] == parent[b]) // ���� ��尡 ����
		return parent[a];

	if (a == 1 || b == 1) // �� ��� �� root ��尡 �ִ�
		return 1;

	if (depth[a] == depth[b]) // depth�� ������ ������ �˻�
		return LCA(parent[a], parent[b]);
	else
		return LCA(a, parent[b]); // depth�� �ٸ���, depth�� ���� ���� ����� ��
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// �Է�1: ���� ����
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		cin >> a >> b;

		// �� ���� ����Ǿ� �ִ�.
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// ��� ������ �Է¹ޱ� �������� ���� �θ��̰� ���� �ڽ����� �Ǵ��� �� ����.

	// ó��: get depth
	// ���: depth�� ��� ���ϴ°�?
	visited[1] = true; // "��Ʈ�� 1���̴�.""��Ʈ�� 1���̴�.""��Ʈ�� 1���̴�.""��Ʈ�� 1���̴�."
	calcTree(0, 1, 0);

	// �Է�2
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		cout << LCA(a, b) << '\n'; // �ٷ� ���
	}

	return 0;
}