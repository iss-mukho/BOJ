// 백준 1786: 찾기(플래티넘 V), https://www.acmicpc.net/problem/1786
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 1000001;

string P, T;
int table[MAX] = { 0, };
vector<int> answer;

void KMP() {
	int i = 0;
	for (int j = 1; j < T.length(); ++j) {
		while (i > 0 && T[i] != T[j]) i = table[i - 1];
		if (T[i] == T[j]) table[j] = ++i;
	}

	i = 0;
	for (int j = 0; j < P.length(); ++j) {
		while (i > 0 && T[i] != P[j]) i = table[i - 1];
		
		if (T[i] != P[j]) continue;
		++i;

		if (i != T.length()) continue;
		answer.push_back(j - i + 1);
		i = table[i - 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getline(cin, P);
	getline(cin, T);

	KMP();

	cout << answer.size() << '\n';
	for (auto a : answer)
		cout << a + 1 << ' ';
	cout << '\n';

	return 0;
}
