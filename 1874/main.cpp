#include <iostream>
#include <stack>
using namespace std;
stack<int> store;
int input[100001] = {};
char output[200001] = {};
int main() {
	int n, idx = 1, a = 1;
	cin >> n;
	int top = 0;
	for (int i = 1; i <= n; i++)
		cin >> input[i];
	for (int i = 1; i <= n; i++) {
		store.push(i);
		output[a++] = '+';
		top = store.top();
		for (int x = idx; x <= i; x++) {
			if (top == input[idx]) {
				store.pop();
				if(store.size())
					top = store.top();
				output[a++] = '-';
				idx++;
			}
		}
	}
	if (!store.size())
		for (int i = 1; i <= n * 2; i++)
			cout << output[i] << '\n';
	else
		cout << "NO" << '\n';
	return 0;
}