#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define MAX 1e18
#define MOD 1000000007
int n;

int dp[22][(1 << 22)];


int solve(vector<vector<int>>&arr, int i, int womenset) {
	if (i == n + 1) {
		if (womenset == 0)
			return 1;
		return 0;
	}

	if (dp[i][womenset] != -1)
		return dp[i][womenset];

	int ans = 0;
	for (int w = 0; w < n; w++) {
		int  avail = (1 << w)&womenset;

		if (avail && arr[i][w + 1])
			ans = (ans + solve(arr, i + 1, womenset ^ (1 << w))) % MOD;
	}
	return dp[i][womenset] = ans;
}

signed main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;

	vector<vector<int>>arr(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));

	cout << solve(arr, 1, (1 << n) - 1) << "\n";

	return 0;

}