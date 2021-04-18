#include <iostream>
#include <time.h>
#include <random>
using namespace std;
int main() {
	int n;
	srand(unsigned(time(NULL)));
	n = rand() % 10000 + 1;
	cout << n << '\n';
	return 0;
}