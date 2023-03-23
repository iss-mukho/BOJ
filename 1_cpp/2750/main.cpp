#include <iostream>
using namespace std;
void bubble_sort(int a[], int n);
int main() {
	int N, * ary;
	cin >> N;
	ary = new int[N];
	for (int i = 0; i < N; i++)
		cin >> ary[i];
	bubble_sort(ary, N);
	for (int i = 0; i < N; i++)
		cout << ary[i] << '\n';
}
void bubble_sort(int a[], int n) {
	for (int m = 0; m < n - 1; m++) {
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
}