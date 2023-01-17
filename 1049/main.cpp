#include <iostream>
#include <algorithm>
using namespace std;

int N, M, p, o, costP = 1001, costO = 1001, answer = 0, r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// �Է�
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> p >> o;
		costP = min(costP, p);
		costO = min(costO, o);
	}

	// ó��
	if (costP >= costO * 6) // ���� ����
		answer = costO * N;
	else {
		if (costP < costO) { // ���� ��Ű��
			if (N % 6 == 0) // N�� ���
				answer = costP * (N / 6);
			else // (N-1) + ������
				answer = costP * (N / 6) + costP;
		}
		else {
			if(N%6==0) // ���� ��Ű��
				answer = costP * (N / 6);
			else { // ��Ű�� ����
				r = costO * (N % 6); // ������ ����
				if (costP < r) // (N-1) + ������(��Ű��)
					answer = costP * (N / 6) + costP;
				else // (N-1) + ������(����)
					answer = costP * (N / 6) + r;
			}
		}
	}
	
	// ���
	cout << answer << '\n';

	return 0;
}