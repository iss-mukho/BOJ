#include <iostream>
using namespace std;

int main() {
	int arr[10] = {};
	int cnt = 10;
	
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		arr[i] %= 42;
	}

	for (int i = 0; i < 9; i++)
		for (int j = i + 1; j < 10; j++)
			if (arr[j] != -1 && arr[i] == arr[j]){
				arr[j] = -1;
				cnt--;
			}

	cout << cnt << '\n';

	return 0;
}