#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, R; // T = �׽�Ʈ ���̽��� ����, R = ���ڸ� �ݺ��� Ƚ��
	string S; // S = �Է¹��� ���ڿ�
	cin >> T;
	for (int i = 0; i < T; i++) {
		string P; // P = S�� R�� �ݺ��� ���ڿ�
		cin >> R >> S;
		for (int j = 0; j < S.size(); j++)
			for (int k = 0; k < R; k++)
				P += S[j];
		cout << P << '\n';
	}
	return 0;
}