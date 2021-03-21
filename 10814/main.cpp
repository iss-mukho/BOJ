#include <iostream>
#include <string>
using namespace std;
string sorted[100000][2];
string input[100001][2];
void merge(string ary[][2], int start, int mid, int end);
void merge_sort(string ary[][2], int start, int end);
int main() {
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
		cin >> input[i][0] >> input[i][1];
	merge_sort(input, 0, N - 1);
	for (int i = 0;i < N;i++)
		cout << input[i][0] << ' ' << input[i][1] << '\n';
	return 0;
}
void merge(string ary[][2], int start, int mid, int end) {
	int front = start, back = mid + 1, index = start;
	while (front <= mid && back <= end) {
		if (stoi(ary[front][0]) <= stoi(ary[back][0])) {
			sorted[index][0] = ary[front][0];
			sorted[index][1] = ary[front][1];
			front++;
		}
		else {
			sorted[index][0] = ary[back][0];
			sorted[index][1] = ary[back][1];
			back++;
		}
		index++;
	}
	if (front > mid) {
		for (back;back <= end;back++) {
			sorted[index][0] = ary[back][0];
			sorted[index][1] = ary[back][1];
			index++;
		}
	}
	else {
		for (front;front <= mid;front++) {
			sorted[index][0] = ary[front][0];
			sorted[index][1] = ary[front][1];
			index++;
		}
	}
	for (int i = start;i <= end;i++) {
		ary[i][0] = sorted[i][0];
		ary[i][1] = sorted[i][1];
	}
}
void merge_sort(string ary[][2], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(ary, start, mid);
		merge_sort(ary, mid + 1, end);
		merge(ary, start, mid, end);
	}
}