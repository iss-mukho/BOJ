#include <iostream>
using namespace std;
int sorted[1000000];
void merge(int ary[], int s, int m, int e);
void merge_sort(int ary[], int s, int e);
int main() {
	int N, *ary;
	cin >> N;
	ary = new int[N];
	for (int i = 0; i < N; i++)
		cin >> ary[i];
	merge_sort(ary, 0, N-1);
	for (int i = 0; i < N; i++)
		cout << ary[i] << '\n';
	return 0;
}
void merge(int ary[], int s, int m, int e) {
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= e) {
		if (ary[i] < ary[j]) {
			sorted[k] = ary[i];
			i++;
		}
		else {
			sorted[k] = ary[j];
			j++;
		}
		k++;
	}
	if (i > m) {
		for (int t = j; t <= e; t++) {
			sorted[k] = ary[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= m; t++) {
			sorted[k] = ary[t];
			k++;
		}
	}
	for (int t = s; t <= e; t++)
		ary[t] = sorted[t];
}
void merge_sort(int ary[], int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		merge_sort(ary, s, m);
		merge_sort(ary, m + 1, e);
		merge(ary, s, m, e);
	}
}