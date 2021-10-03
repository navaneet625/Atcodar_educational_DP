#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 100005;
int dp[N];
int n, k;
int solve(vector<int>&h, int n) {
	if (n == 0 or n == 1)
		return dp[n] = 0;
	if (dp[n] != -1)
		return dp[n];

	int min_val = INT_MAX;
	for (int i = 1; i <= k; i++) {
		if (n - i > 0) {
			int val = solve(h, n - i) + abs(h[n - 1] - h[n - 1 - i]);
			min_val = min(min_val, val);
		}
	}
	return dp[n] = min_val;
}


signed main() {

	cin >> n >> k;
	vector<int> h(n);

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	// memset(dp, -1, sizeof(dp));
	// cout << solve(h, n) << "\n";

	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		int min_val = INT_MAX;
		for (int t = 1; t <= k; t++) {
			if (i - t > 0) {
				int val = abs(h[i - 1] - h[i - 1 - t]) + dp[i - t];
				min_val = min(val, min_val);
			}
		}
		dp[i] = min_val;
	}
	cout << dp[n] << "\n";

}