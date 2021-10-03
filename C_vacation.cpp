#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 100005;
int dp[N + 1][4];
int n;


//top down
int solve(vector<vector<int>>&arr, int n, int t) {
	if (n == 1)
		return arr[0][t];
	if (dp[n][t] != -1)
		return dp[n][t];
	int a = arr[n - 1][t] + solve(arr, n - 1, (t + 1) % 3);
	int b = arr[n - 1][t] + solve(arr, n - 1, (t + 2) % 3);
	return dp[n][t] = max(a, b);
}


signed main() {
	cin >> n;
	vector<vector<int>>arr(n);
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		arr[i] = {a, b, c};
	}

	// memset(dp, -1, sizeof(dp));
	// int ans = max(solve(arr, n, 0), max(solve(arr, n, 1), solve(arr, n, 2)));
	// cout << ans << "\n";


	//bottom up

	dp[1][0] = arr[0][0];
	dp[1][1] = arr[0][1];
	dp[1][2] = arr[0][2];

	for (int i = 2; i <= n; i++) {
		dp[i][0] = arr[i - 1][0] + max(dp[i - 1][1] , dp[i - 1][2]);
		dp[i][1] = arr[i - 1][1] + max(dp[i - 1][0] , dp[i - 1][2]);
		dp[i][2] = arr[i - 1][2] + max(dp[i - 1][0] , dp[i - 1][1]);
	}
	cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
}