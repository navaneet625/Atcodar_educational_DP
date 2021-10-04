#include<bits/stdc++.h>
using namespace std;


double dp[302][302][302];

double solve(int x1, int x2, int x3, int &n) {
	if (x1 < 0 or x2 < 0 or x3 < 0) {
		return 0;
	}

	if (x1 == 0 && x2 == 0 && x3 == 0)
		return 0;

	if (dp[x1][x2][x3] > -0.99) {
		return dp[x1][x2][x3];
	}
	double val = n + x1 * solve(x1 - 1, x2, x3, n) +
	             x2 * solve(x1 + 1, x2 - 1, x3, n) +
	             x3 * solve(x1, x2 + 1, x3 - 1, n);

	val = val / (x1 + x2 + x3);

	return dp[x1][x2][x3] = val;

}

int main() {
	int n;
	cin >> n;

	int x, x1, x2, x3;
	x1 = x2 = x3 = 0;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 1)
			x1++;
		if (x == 2)
			x2++;
		if (x == 3)
			x3++;
	}
	memset(dp, -1, sizeof(dp));
	cout << setprecision(20) << solve(x1, x2, x3, n) << "\n";
	return 0;
}