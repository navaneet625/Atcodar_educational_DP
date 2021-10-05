#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007

int dp[100002][2];
int n;


int solve(vector<vector<int>>&adj, int node , int col, int parent) {

	if (dp[node][col] != -1)
		return dp[node][col];

	int ans = 0, ans1 = 1;

	for (auto x : adj[node]) {
		if (x != parent) {
			ans1 = (ans1 * solve(adj, x, 0, node)) % MOD;
		}
	}
	ans += ans1;
	if (!col) {
		int ans2 = 1;
		for (auto x : adj[node]) {
			if (x != parent) {
				ans2 = (ans2 * solve(adj, x, 1, node)) % MOD;
			}
		}
		ans = (ans + ans2) % MOD;
	}
	return dp[node][col] = ans;
}


signed main() {

	cin >> n;

	vector<vector<int>>adj(n + 1);
	int a, b;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(dp, -1, sizeof(dp));

	//0 =white  ,, 1 = black

	int ans = solve(adj, 1, 0, -1);

	cout << ans << "\n";

	return 0;

}