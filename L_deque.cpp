#include<bits/stdc++.h>
using namespace std;
#define int long long int

int dp[3001][3001];

int solve(int arr[], int i, int j, int turn) {
	if (i > j)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (turn == 1) {
		return dp[i][j] = max(arr[i] + solve(arr, i + 1, j, 0), arr[j] + solve(arr, i, j - 1, 0));
	}
	else {
		return dp[i][j] = min(solve(arr, i + 1, j, 1), solve(arr, i, j - 1, 1));
	}

}


signed main() {
	int n;
	cin >> n;
	int arr[n + 1];
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}


	memset(dp, -1, sizeof(dp));

	cout << 2 * solve(arr, 1, n, 1) - sum << "\n";

	return 0;

}