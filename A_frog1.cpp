#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int dp[N];

int solve(int n, vector<int>&h) {
	if (n == 1)
		return 0;
	if (n == 2)
		return abs(h[n - 1] - h[n - 2]);
	if (dp[n] != -1)
		return dp[n];
	int a = solve(n - 1, h) + abs(h[n - 1] - h[n - 2]);
	int b = solve(n - 2, h) + abs(h[n - 1] - h[n - 3]);
	return dp[n] = min(a, b);
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// memset(dp, -1, sizeof(dp));
	// cout << solve(n, arr) << "\n";
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = abs(arr[0] - arr[1]);

	for (int i = 3; i <= n; i++) {
		dp[i] = min(abs(arr[i - 1] - arr[i - 2]) + dp[i - 1],
		            abs(arr[i - 1] - arr[i - 3]) + dp[i - 2]);
	}

	cout << dp[n] << "\n";

}