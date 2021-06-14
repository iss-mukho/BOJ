#include <iostream>
#include <list>
using namespace std;
list<char> l;
list<char>::iterator iter;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, i;
	string input;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> input;
		iter = l.begin();
		for (char a : input) {
			if (a == '<') {
				if (iter == l.begin())
					continue;
				--iter;
			}
			else if (a == '>') {
				if (iter == l.end())
					continue;
				++iter;
			}
			else if (a == '-') {
				if (iter == l.begin())
					continue;
				iter = l.erase(--iter);
			}
			else
				l.insert(iter, a);
		}
		for (list<char>::iterator it = l.begin(); it != l.end(); ++it)
			cout << *it;
		cout << '\n';
		l.clear();
	}
	return 0;
}