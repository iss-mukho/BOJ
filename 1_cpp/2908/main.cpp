#include <iostream>
#include <string>
using namespace std;

void reverse(string& s);
int main() {
	string A, B;
	cin >> A >> B;
	reverse(A);
	reverse(B);
	if (stoi(A) > stoi(B))
		cout << A << '\n';
	else
		cout << B << '\n';
	return 0;
}
void reverse(string& s) {
	char temp;
	temp = s[0];
	s[0] = s[2];
	s[2] = temp;
}