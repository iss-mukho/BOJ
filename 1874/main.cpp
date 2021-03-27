#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> store;
string output;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int input[100001] = {};
	int n, i, x, comp_idx = 1;
	cin >> n;
	for (i = 1; i <= n; ++i)
		cin >> input[i];
	int top = 0;
	for (i = 1; i <= n; ++i) {
		store.push(i);
		output += "+\n";
		top = store.top();
		for (x = comp_idx; x <= i; ++x) {
			if (top == input[comp_idx]) {
				store.pop();
				if (store.size())
					top = store.top();
				output += "-\n";
				++comp_idx;
			}
		}
	}
	if (!store.size())
		cout << output << '\n';
	else
		cout << "NO" << '\n';
	return 0;
}