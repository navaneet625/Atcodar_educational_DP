#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define MAX 1e18

int dp[1000][1000];
int sum[1000][1000];

int  solve(int arr[] , int i, int j) {

	if (i >= j)
		return 0LL;

	if (dp[i][j] != -1)
		return dp[i][j];


	int min_cost = MAX;

	for (int k = i; k < j; k++) {
		min_cost = min(min_cost, sum[i][j] + solve(arr, i, k) + solve(arr, k + 1, j));
	}
	return dp[i][j] = min_cost;
}



void precompute(int arr[], int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			sum[i][j] = arr[j] + ((j == i) ? 0 : sum[i][j - 1]);
		}
	}
}
signed main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int arr[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	precompute(arr, n);

	memset(dp, -1, sizeof(dp));

	int ans = solve(arr, 1, n);

	cout << ans << "\n";

	return 0;

}