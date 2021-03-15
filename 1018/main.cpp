#include <iostream>
#include <string>
using namespace std;
int main() {
	string* chess;
	int M, N, min = 999999;
	cin >> M >> N;
	chess = new string[M];
	for (int i = 0; i < M; i++)
		cin >> chess[i];
	for (int i = 0; i + 7 < M; i++) {
		for (int j = 0; j + 7 < N; j++) {
			int temp1 = 0, temp2 = 0;
			string test1, test2;
			if (chess[i][j] == 'B') {
				test1 = "BWBWBWBW";
				test2 = "WBWBWBWB";
			}
			else {
				test1 = "WBWBWBWB";
				test2 = "BWBWBWBW";
			}
				
			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {
					if (a % 2 == 0) {
						if (chess[i + a][j + b] != test1[b])
							temp1++;
						if (chess[i + a][j + b] != test2[b])
							temp2++;
					}
					else {
						if (chess[i + a][j + b] == test1[b])
							temp1++;
						if (chess[i + a][j + b] == test2[b])
							temp2++;
					}
				}
			}
			int temp = temp1 < temp2 ? temp1 : temp2;
			if (temp < min)
				min = temp;
		}
	}
	cout << min << '\n';
	return 0;
}