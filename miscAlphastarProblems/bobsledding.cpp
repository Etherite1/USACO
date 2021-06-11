#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define endl "\n"

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

vector<pair<ll, ll>> a(100010);
ll f[100010];

void solve()
{
    ll l, n; cin >> l >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin() + 1, a.begin() + n + 1);
    f[0] = 1; a[n + 1].first = l; a[n + 1].second = 1e9;
    for(int i = n; i >= 1; i--) a[i].second = min(a[i].second, a[i + 1].second + a[i + 1].first - a[i].first);
    ll ans = 0;
    for(int i = 1; i <= n + 1; i++)
    {
        f[i] = min(a[i].second, f[i - 1] + a[i].first - a[i - 1].first);
        ans = max(ans, (a[i].first - a[i - 1].first + f[i] + f[i - 1]) / 2); 
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
