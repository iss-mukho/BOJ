#include <iostream>
using namespace std;
int main() {
	int S, Si, Sm, Ss, Sk;
	int T, Ti, Tm, Ts, Tk;
	cin >> Si >> Sm >> Ss >> Sk;
	cin >> Ti >> Tm >> Ts >> Tk;
	S = Si + Sm + Ss + Sk;
	T = Ti + Tm + Ts + Tk;
	if (S >= T)
		cout << S << '\n';
	else
		cout << T << '\n';
	return 0;
}