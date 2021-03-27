#include <iostream>
#include <stack>
using namespace std;
stack<int> store;
int input[100001] = {};
char output[200001] = {};
int main() {
	int n, comp_idx = 1, out_idx = 1;
	cin >> n;
	int top = 0;
	for (int i = 1; i <= n; i++)
		cin >> input[i];
	for (int i = 1; i <= n; i++) {
		store.push(i);
		output[out_idx++] = '+';
		top = store.top();
		for (int x = comp_idx; x <= i; x++) {
			if (top == input[comp_idx]) {
				store.pop();
				if(store.size())
					top = store.top();
				output[out_idx++] = '-';
				comp_idx++;
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