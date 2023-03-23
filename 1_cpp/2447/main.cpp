#include <iostream>
#include <cstring> // memset
using namespace std;
void star(char **ary, int n, int x, int y); // º°Âï±â, N, x index, y index
int main() {
	char** recursion = new char* [2188];
	for (int i = 0; i < 2188; i++) {
		recursion[i] = new char[2188];
		memset(recursion[i], ' ', sizeof(char) * 2188);
	}
	int N; // 3ÀÇ °ÅµìÁ¦°ö. N=3^k (1<=k<8)
	cin >> N;
	star(recursion, N, 1, 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) 
			cout << recursion[i][j];
		cout << '\n';
	}
	return 0;
}
void star(char **ary, int n, int x, int y) {
	if (n == 1) 
		ary[x][y] = '*';
	else {
		int blank = n / 3;
		star(ary, blank, x, y); // 1,1
		star(ary, blank, x, y + blank); // 1,2
		star(ary, blank, x, y + (blank * 2)); // 1,3
		star(ary, blank, x + blank, y); // 2,1
		star(ary, blank, x + blank, y + (blank * 2)); // 2,3
		star(ary, blank, x + (blank * 2), y); // 3,1
		star(ary, blank, x + (blank * 2), y + blank); // 3,2
		star(ary, blank, x + (blank * 2), y + (blank * 2)); // 3,3
	}
}