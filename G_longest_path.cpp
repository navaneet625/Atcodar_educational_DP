#include<bits/stdc++.h>
using namespace std;
#define int  long long int

vector<vector<int>>adj(100005);
vector<int> dp(100005, -1);

int  solve(int node) {

	if (dp[node] != -1)
		return dp[node];

	int max_val = 0;
	bool child = false;
	for (auto x : adj[node]) {
		child = true;
		max_val = max(max_val, solve(x));
	}
	return dp[node] = child ? 1 + max_val : 0;
}

signed main() {

	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, solve(i));
	}
	cout << ans << "\n";
}