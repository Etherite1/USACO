#include "bits/stdc++.h"

using namespace std;

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

#define pii pair<int, int>
#define pb push_back

const int N = 250;
vector<int> dist(N, 1e9);
vector<pair<int, pii>> edges;

void solve()
{
    setIO("jobhunt");
    int d, m, n, f, s; cin >> d >> m >> n >> f >> s;   
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        edges.pb({-d, {u, v}});
    }
    for(int i = 0; i < f; i++)
    {
        int u, v, cost; cin >> u >> v >> cost;
        edges.pb({cost - d, {u, v}});
    }
    dist[s] = -d;
    for(int i = 0; i < n - 1; i++)
    {
        for(auto e : edges)
        {
            dist[e.second.second] = min(dist[e.second.second], dist[e.second.first] + e.first);
        }
    }
    bool flag = 0;
    for(auto e : edges)
    {
        if(dist[e.second.second] > dist[e.second.first] + e.first) {flag = 1; break;}
    }
    if(flag) cout << "-1\n";
    else
    {
        int mn = 1e9;
        for(int i = 1; i <= n; i++) mn = min(mn, dist[i]);
        cout << -mn << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();
}
