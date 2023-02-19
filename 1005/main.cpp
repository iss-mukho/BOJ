// ���� 1005: ACM Craft(��� III)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

const int MAX = 1000;
int T, N, K, D, X, Y, W;
vector<int> build[MAX + 1];
int buildTime[MAX + 1];
int curMax[MAX + 1]; // indegree�� 0�� �Ǳ� ���� �ִ� �ð� ����
int indegree[MAX + 1];

void init() {
	for (int i = 1; i <= N; ++i) build[i].clear();
	fill_n(buildTime + 1, N, 0);
	fill_n(curMax + 1, N, 0);
	fill_n(indegree + 1, N, 0);
}
void topologySort() {
	deque<int> dq;

	for (int i = 1; i <= N; ++i)
		if (indegree[i] == 0)
			dq.push_back(i);

	while (!dq.empty()) {
		int s = dq.front();
		dq.pop_front();

		for (auto e : build[s]) {
			if (--indegree[e] == 0) {
				dq.push_back(e);
				buildTime[e] += max(curMax[e], buildTime[s]);
			}
			else curMax[e] = max(curMax[e], buildTime[s]); // indegree�� 0�� �ƴ� ��, �ִ� �ð� ���� ����
		}
	}
}

int main() {
	// �Է�: �׽�Ʈ���̽��� ����
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &N, &K); // �Է�: �ǹ��� ������ �Ǽ����� ��Ģ ����

		 // �Է�: �Ǽ� �ð�
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &D);
			buildTime[i] = D;
		}

		// �Է�: �Ǽ� ����
		for (int i = 0; i < K; ++i) {
			scanf("%d %d", &X, &Y);
			build[X].push_back(Y);
			++indegree[Y];
		}

		// �Է�: �ǹ��� ��ȣ
		scanf("%d", &W);

		// ó��: ���� ����
		topologySort();

		// ���
		printf("%d\n", buildTime[W]);

		// �ʱ�ȭ
		init();
	}

	return 0;
}