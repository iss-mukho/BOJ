// Made By Mukho
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
vector<pair<int, int>> input; // <�߿䵵, ������ȣ>
priority_queue<pair<int, int>> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int TC, N, M, i, j, temp, cnt;
	// �Է�
	cin >> TC;
	for (i = 0; i < TC; ++i) {
		cin >> N >> M;
		for (j = 0; j < N; ++j) {
			cin >> temp;
			input.push_back({ temp, j }); // <�߿䵵, ������ȣ>
			pq.push(input[j]);
		}
		cnt = 1;
		// �˰���
		while (true) {
			// ������ ������ �� ���� �������� �߿䵵�� ���� ������ �ϳ��� �ִٸ�,
			if (input[0].first < pq.top().first) {
				pair<int, int> tp = input[0];
				// �� ������ �μ����� �ʰ� Queue�� ���� �ڿ� ���ġ �Ѵ�.
				input.erase(input.begin());
				input.push_back(tp);
			}
			//  �׷��� �ʴٸ� �ٷ� �μ⸦ �Ѵ�.
			else {
				// ���
				if (input[0].second == M) {
					cout << cnt << '\n';
					cnt = 1; // �� �׽�Ʈ���̽��� ���� �ʱ�ȭ
					break;
				}
				// �����δ� ��� ������ �ʿ��ϱ� ������ ó���ϴ� �κ�
				else {
					input.erase(input.begin());
					pq.pop();
					++cnt;
				}
			}
		}
		// �� �׽�Ʈ���̽��� ���� �ʱ�ȭ
		input.clear();
		pq = priority_queue<pair<int, int>>();
	}
	return 0;
}