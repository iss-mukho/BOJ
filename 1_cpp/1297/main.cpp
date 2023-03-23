#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int diagonal, height, weight, H, W;
	double x;
	cin >> diagonal >> H >> W;
	x = sqrt((double)(pow(diagonal, 2) / (pow(H, 2) + pow(W, 2))));
	height = floor(H * x);
	weight = floor(W * x);
	cout << height << ' ' << weight << '\n';
	return 0;
}