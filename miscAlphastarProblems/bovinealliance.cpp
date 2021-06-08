#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

const int N = 1e5 + 10;
vector<int> adj[N];
int vis[N], ncnt = 0, ecnt = 0;

void dfs(int curr)
{
    ncnt++;
    ecnt += adj[curr].size();
    for(auto adjnode : adj[curr])
    {
        if(vis[adjnode]) continue;
        vis[adjnode] = 1;
        dfs(adjnode);
    }
}

void solve()
{
    setIO("alliance");
    int n, m; cin >> n >> m;
    long long ans = 1;
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;
        vis[i] = 1;
        ncnt = 0, ecnt = 0;
        dfs(i);
        ecnt /= 2;
        // cerr << i << " " << ncnt << " " << ecnt << endl;
        if(ecnt == ncnt) ans = (ans * 2) % MOD;
        else ans = (ans * ncnt) % MOD;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();
}
