#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define endl "\n"
#define pll pair<ll, ll>

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int n;
vector<pll> a;
ll orig = 0;

ll get()
{
    sort(a.begin(), a.end());
    set<pll> right;
    ll ans = 0, mnleft = 1e18, mxleft = 0;
    for(int i = 0; i < n; i++)
    {
        right.insert({a[i].second, a[i].first});
    }
    for(int i = 0; i < n - 1; i++)
    {
        mnleft = min(mnleft, a[i].second); mxleft = max(mxleft, a[i].second);
        right.erase({a[i].second, a[i].first});
        ll ansleft = (mxleft - mnleft) * (a[i].first - a[0].first);
        ll ansright = ((*right.rbegin()).first - (*right.begin()).first) * (a[n - 1].first - a[i + 1].first);
        ans = max(ans, orig - ansleft - ansright);
    }
    return ans;
}

void solve()
{
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i.first >> i.second;
    sort(a.begin(), a.end());
    orig = a[n - 1].first - a[0].first;
    ll mn = 1e18, mx = -1;
    for(auto i : a) mn = min(mn, i.second), mx = max(mx, i.second);
    orig *= (mx - mn);
    ll ans = get();
    for(auto &i : a) swap(i.first, i.second);
    ans = max(ans, get());
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
