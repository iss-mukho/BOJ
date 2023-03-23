#include <iostream>
using namespace std;
int dot[100000][2];
int sorted[100000][2];
void merge(int ary[][2], int start, int mid, int end);
void merge_sort(int ary[][2], int start, int end);
int main() {
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
		cin >> dot[i][0] >> dot[i][1];
	merge_sort(dot, 0, N-1);
	for (int i = 0;i < N;i++)
		cout << dot[i][0] << ' ' << dot[i][1] << '\n';
	return 0;
}
void merge(int ary[][2], int start, int mid, int end) {
	int s = start, m = mid+1, a = start;
	while (s <= mid && m <= end) {
		if (ary[s][0] < ary[m][0]) {
			sorted[a][0] = ary[s][0];
			sorted[a][1] = ary[s][1];
			s++;
		}
		else if (ary[s][0] == ary[m][0]) {
			if (ary[s][1] < ary[m][1]) {
				sorted[a][0] = ary[s][0];
				sorted[a][1] = ary[s][1];
				s++;
			}
			else {
				sorted[a][0] = ary[m][0];
				sorted[a][1] = ary[m][1];
				m++;
			}
		}
		else {
			sorted[a][0] = ary[m][0];
			sorted[a][1] = ary[m][1];
			m++;
		}
		a++;
	}
	if (s > mid) {
		for (int i = m;i <= end;i++) {
			sorted[a][0] = ary[i][0];
			sorted[a][1] = ary[i][1];
			a++;
		}
	}
	else {
		for (int i = s;i <= mid;i++) {
			sorted[a][0] = ary[i][0];
			sorted[a][1] = ary[i][1];
			a++;
		}
	}
	for (int i = start;i <= end;i++) {
		ary[i][0] = sorted[i][0];
		ary[i][1] = sorted[i][1];
	}
}
void merge_sort(int ary[][2], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(dot, start, mid);
		merge_sort(dot, mid + 1, end);
		merge(dot, start, mid, end);
	}
}