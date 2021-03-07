#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, R; // T = 테스트 케이스의 개수, R = 문자를 반복할 횟수
	string S; // S = 입력받을 문자열
	cin >> T;
	for (int i = 0; i < T; i++) {
		string P; // P = S를 R번 반복한 문자열
		cin >> R >> S;
		for (int j = 0; j < S.size(); j++)
			for (int k = 0; k < R; k++)
				P += S[j];
		cout << P << '\n';
	}
	return 0;
}