#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007


signed main() {
	int n, k;
	cin >> n >> k;

	int arr[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int dp[n + 1][k + 1];

	memset(dp, 0, sizeof(dp));

	for (int i = 0; i <= k; i++) {
		dp[1][i] = (i > arr[1]) ? 0 : 1;
	}


	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = (MOD + dp[i][j - 1] + dp[i - 1][j] - ((j - arr[i] - 1 >= 0) ? dp[i - 1][j - arr[i] - 1] : 0)) % MOD;
		}
	}

	cout << dp[n][k] << "\n";
}