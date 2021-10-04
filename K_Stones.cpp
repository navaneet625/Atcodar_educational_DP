#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, s;
	cin >> n >> s;

	int arr[n];

	for (auto &x : arr)
		cin >> x;

	int dp[s + 1];
	memset(dp, 0, sizeof(dp));


	for (int i = 1; i <= s; i++) {
		for (int x : arr) {
			if (x > i)
				continue;
			if (!dp[i - x])
				dp[i] = 1;
		}
	}
	if (dp[s]) {
		cout << "First\n";
	} else {
		cout << "Second\n";
	}
}