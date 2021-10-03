#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define inf 1e9+1

signed main() {
	int n, W;
	cin >> n >> W;
	vector<int> wt(n), val(n);

	for (int i = 0; i < n; i++) {
		cin >> wt[i] >> val[i];
	}
	int max_val = n * 1000;
	int dp[n + 1][max_val + 1];


	//select min weight so init with maximum weight i.e.=1e9
	memset(dp, inf, sizeof(dp));

	dp[0][0] = 0;
	dp[0][val[0]] = wt[0];

	for (int i = 1; i < n; i++ ) {
		dp[i][0] = 0;
		for (int j = 1; j <= max_val; j++) {
			if (val[i] > j) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = min(dp[i - 1][j], wt[i] + dp[i - 1][j - val[i]]);
			}
		}
	}

	int ans = 0;
	for (int i = max_val + 1; i >= 0; i--) {
		if (dp[n - 1][i] <= W)
		{
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
}