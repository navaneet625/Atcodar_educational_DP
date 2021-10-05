#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
ll n, k;

void mul(vector<vector<ll>>&a, vector<vector<ll>>&b)
{
    vector<vector<ll>>temp(n, vector<ll>(n));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            temp[i][j] = 0;
            for (ll k = 0; k < n; k++)
            {
                temp[i][j] = (temp[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
            a[i][j] = temp[i][j];
    }
    return ;
}

ll power(vector<vector<ll>>&mat)
{
    vector<vector<ll>>res(n, vector<ll>(n));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i == j)
                res[i][j] = 1;
            else
                res[i][j] = 0;
        }
    }
    while (k)
    {
        if (k & 1)
            mul(res, mat);
        mul(mat, mat);
        k = k >> 1;
    }
    // return res[0][n-1]%MOD;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = (ans + res[i][j]) % MOD;
        }
    }

    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n >> k;
    vector<vector<ll>>mat(n, vector<ll>(n));

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++) {
            cin >> mat[i][j];
        }

    cout << power(mat);

    return 0;
}