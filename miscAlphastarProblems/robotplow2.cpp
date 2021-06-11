#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define pll pair<long long, long long>
#define pb push_back

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

void solve()
{
    ll x, y, n; cin >> x >> y >> n;
    vector<vector<pll>> adds(x + 1), subs(x + 1);
    for(int i = 0; i < n; i++)
    {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        adds[a].pb({b, d});
        subs[c].pb({b, d});
    }
    ll run = 0, ans = 0;
    vector<int> line(y + 1);
    for(int i = 0; i <= x; i++)
    {
        for(auto j : adds[i])
        {
            for(int k = j.first; k <= j.second; k++) 
            {
                if(line[k] == 0) run++;
                line[k]++;
            }
        }
        ans += run;
        for(auto j : subs[i])
        {
            for(int k = j.first; k <= j.second; k++)
            {
                if(line[k] == 1) run--;
                line[k]--;
            }
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
