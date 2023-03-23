#include <iostream>
#include <string>
using namespace std;
string sorted[20001];
void merge(string ary[], int start, int mid, int end);
void merge_sort(string ary[], int start, int end);
string words[20001];
int main() {
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
		cin >> words[i];
	merge_sort(words, 0, N - 1);
	for (int i = 0;i < N;i++) {
		if (words[i] == words[i + 1]) // 중복된 값 출력 x
			continue;
		cout << words[i] << '\n';
	}
	return 0;
}
void merge(string ary[], int start, int mid, int end) {
	int front = start, back = mid + 1, index = start;
	while (front <= mid && back <= end) {
		if (ary[front].size() < ary[back].size()) {
			sorted[index] = ary[front];
			front++;
		}
		else if (ary[front].size() == ary[back].size()) {
			if (ary[front] < ary[back]) {
				sorted[index] = ary[front];
				front++;
			}
			else {
				sorted[index] = ary[back];
				back++;
			}
		}
		else {
			sorted[index] = ary[back];
			back++;
		}
		index++;
	}
	if (front > mid) {
		for (back;back <= end;back++) {
			sorted[index] = ary[back];
			index++;
		}
	}
	else {
		for (front;front <= mid;front++) {
			sorted[index] = ary[front];
			index++;
		}
	}
	for (int i = start;i <= end;i++)
		ary[i] = sorted[i];
}
void merge_sort(string ary[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(ary, start, mid);
		merge_sort(ary, mid + 1, end);
		merge(ary, start, mid, end);
	}
}