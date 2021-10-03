#include<bits/stdc++.h>
using namespace std;
#define int  long long int
#define MOD 1000000007
double dp[3005][3005];


double solve(vector<double>&arr, int n, int c) {
	if (c == 0)
		return 1;
	if (n == 0)
		return 0;

	if (dp[n][c] > -0.99 )
		return dp[n][c];
	return dp[n][c] = arr[n - 1] * solve(arr, n - 1, c - 1) + (1 - arr[n - 1]) * solve(arr, n - 1, c);
}

signed main() {
	int n;
	cin >> n;

	vector<double>arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << setprecision(10) << solve(arr, n, (n + 1) / 2) << "\n";
}