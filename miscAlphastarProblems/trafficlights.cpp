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
#define rsz resize

vector<int> rem, col, db, dp;

bool same(int u, int v, int t)
{
    int col1 = col[u], col2 = col[v], trem1 = t, trem2 = t;
    if(trem1 >= rem[u]) 
    {
        trem1 -= rem[u];
        col1 = !col1;
        trem1 %= (db[u] + dp[u]);
        if(col1 == 0) col1 = (trem1 >= db[u]);
        else col1 = trem1 < dp[u];
    }
    if(trem2 >= rem[v])
    {
        trem2 -= rem[v];
        col2 = !col2;
        trem2 %= (db[v] + dp[v]);
        if(col2 == 0) col2 = (trem2 >= db[v]);
        else col2 = trem2 < dp[v];
    }
    return col1 == col2;
}

void solve()
{
    int start, finish; cin >> start >> finish; start--; finish--;
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n); 
    rem.rsz(n); col.rsz(n); db.rsz(n); dp.rsz(n);
    for(int i = 0; i < n; i++)
    {
        char x; cin >> x;
        if(x == 'B') col[i] = 0;
        else col[i] = 1;
        cin >> rem[i] >> db[i] >> dp[i];
    }
    for(int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));
    }
    vector<int> vis(n), dist(n, 2e9);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start}); dist[start] = 0;
    while(!pq.empty())
    {
        int curr = pq.top().second, t = pq.top().first; pq.pop();
        if(vis[curr]) continue;
        vis[curr] = 1;
        for(auto adjnode : adj[curr])
        {
            if(vis[adjnode.second]) continue;
            int nt = t;
            int moves = 0;
            while(!same(curr, adjnode.second, nt) && moves < 2000) nt++, moves++;
            if(!same(curr, adjnode.second, nt)) continue;
            int nd = nt + adjnode.first;
            if(dist[adjnode.second] > nd)
            {
                dist[adjnode.second] = nd;
                pq.push({nd, adjnode.second});
            }
        }
    }
    cout << (dist[finish] == 2e9? 0 : dist[finish]) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();

}
