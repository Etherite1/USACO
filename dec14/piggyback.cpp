#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define endl "\n"
#define all(x) (x).begin(), (x).end()

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

vector<int> dijk(vector<vector<int>> &adj, int start, int cost)
{
    int n = adj.size();
    vector<int> vis(n), dist(n, 1e9);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty())
    {
        pii curr = pq.top(); pq.pop();
        if(vis[curr.second]) continue;
        vis[curr.second] = 1;
        for(auto adjnode : adj[curr.second])
        {
            if(vis[adjnode]) continue;
            if(dist[adjnode] > dist[curr.second] + cost)
            {
                dist[adjnode] = dist[curr.second] + cost;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
    return dist;
}

void solve()
{
    setIO("piggyback");
    int b, e, p, n, m; cin >> b >> e >> p >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // bessie is in field 1, elsie is in field 2
    vector<int> bessie = dijk(adj, 0, b);
    vector<int> elsie = dijk(adj, 1, e);
    vector<int> both = dijk(adj, n - 1, p);
    int mn = 1e9;
    for(int i = 0; i < n; i++) mn = min(mn, bessie[i] + elsie[i] + both[i]);
    cout << mn << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
