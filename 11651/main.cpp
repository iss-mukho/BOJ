#include <iostream>
#include <vector>
using namespace std;
int dot[100001][2];
int sorted[100001][2];
void merge(int ary[][2], int s, int m, int e);
void merge_sort(int ary[][2], int s, int e);
int main() {
	cin.sync_with_stdio(false);
	int N, x, y;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> x >> y;
		dot[i][1] = y;
		dot[i][0] = x;
	}
	merge_sort(dot, 0, N - 1);
	for (int i = 0;i < N;i++)
		cout << dot[i][0] << ' ' << dot[i][1] << '\n';
	return 0;
}
void merge(int ary[][2], int s, int m, int e) {
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= e) {
		if (ary[i][1] < ary[j][1]) {
			sorted[k][1] = ary[i][1];
			sorted[k][0] = ary[i][0];
			i++;
		}
		else if (ary[i][1] == ary[j][1]) {
			if (ary[i][0] < ary[j][0]) {
				sorted[k][1] = ary[i][1];
				sorted[k][0] = ary[i][0];
				i++;
			}
			else {
				sorted[k][1] = ary[j][1];
				sorted[k][0] = ary[j][0];
				j++;
			}
		}
		else {
			sorted[k][1] = ary[j][1];
			sorted[k][0] = ary[j][0];
			j++;
		}
		k++;
	}
	if (i > m) {
		for (int t = j; t <= e; t++) {
			sorted[k][1] = ary[t][1];
			sorted[k][0] = ary[t][0];
			k++;
		}
	}
	else {
		for (int t = i; t <= m; t++) {
			sorted[k][1] = ary[t][1];
			sorted[k][0] = ary[t][0];
			k++;
		}
	}
	for (int t = s; t <= e; t++) {
		ary[t][1] = sorted[t][1];
		ary[t][0] = sorted[t][0];
	}
}
void merge_sort(int ary[][2], int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		merge_sort(ary, s, m);
		merge_sort(ary, m + 1, e);
		merge(ary, s, m, e);
	}
}