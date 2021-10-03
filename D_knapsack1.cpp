#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 100005;
int dp[105][N];
int n, W;
signed main() {
	cin >> n >> W;
	vector<int> wt(n), val(n);

	for (int i = 0; i < n; i++) {
		cin >> wt[i] >> val[i];
	}

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}

	for (int i = 0; i <= W; i++) {
		dp[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			if (wt[i - 1] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
		}
	}

	cout << dp[n][W] << "\n";
}