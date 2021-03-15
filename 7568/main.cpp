#include <iostream>
using namespace std;
int main() {
	int** dungchi; // 키 몸무게 저장
	int* bigger; // 순위 저장
	int N, x, y;
	cin >> N;
	dungchi = new int* [N];
	bigger = new int[N];
	fill_n(bigger, N, 1);
	for (int i = 0; i < N; i++)
		dungchi[i] = new int[2];
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		dungchi[i][0] = x;
		dungchi[i][1] = y;
	}
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (dungchi[i][0] < dungchi[j][0] && dungchi[i][1] < dungchi[j][1])
				bigger[i] += 1;
			else if (dungchi[i][0] > dungchi[j][0] && dungchi[i][1] > dungchi[j][1])
				bigger[j] += 1;
		}
	}
	for (int i = 0; i < N; i++)
		cout << bigger[i] << ' ';
	cout << '\n';
	return 0;
}