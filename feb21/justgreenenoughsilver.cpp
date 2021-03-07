#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vll vector<pair<long long, long long>>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define endl "\n"

void solve()
{
    int n; cin >> n;
    ll grid[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int x; cin >> x;
            if(x < 100) grid[i][j] = 0;
            else if(x == 100) grid[i][j] = 2;
            else grid[i][j] = 1;
        }
    }
    ll pref0[n][n + 1], pref1[n][n + 1], pref2[n][n + 1];
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            pref0[i][j] = pref0[i][j - 1];
            pref1[i][j] = pref1[i][j - 1];
            pref2[i][j] = pref2[i][j - 1];
            if(grid[i][j - 1] == 0) pref0[i][j]++;
            else if(grid[i][j - 1] == 1) pref1[i][j]++;
            else pref2[i][j]++;
        }
    }
    ll ans = 0;
    int good[n];
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++) // {i, j} is left and right row, inclusive from [i, j]
        {
            for(int k = 0; k < n; k++)
            {
                if(pref0[k][j + 1] - pref0[k][i] > 0) {good[k] = 0; continue;};
                if(pref1[k][j + 1] - pref1[k][i] + pref2[k][j + 1] - pref2[k][i] == j - i + 1)
                {
                    if(pref2[k][j + 1] - pref2[k][i] > 0) good[k] = 2;
                    else good[k] = 1;
                }
            }
            ll last = 1e9, cnt = 0;
            for(ll k = 0; k < n; k++)
            {
                if(good[k]) last = min(last, k);
                else
                {
                    if(last == 1e9) continue;
                    ll x = last;
                    for(ll l = last; l < k; l++)
                    {
                        if(good[l] == 2)
                        {
                            cnt += (l - x + 1) * (k - l);
                            x = l + 1;
                        }
                    }
                    last = 1e9;
                }
            }
            if(last != 1e9)
            {
                ll l = last;
                for(ll k = last; k < n; k++)
                {
                    if(good[k] == 2)
                    {
                        cnt += (k - l + 1) * (n - k);
                        l = k + 1;
                    }
                }
            }
            ans += cnt;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

 	solve();

    return 0;
}