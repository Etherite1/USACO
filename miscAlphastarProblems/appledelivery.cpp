#include "bits/stdc++.h"

using namespace std;

#define int long long
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

vector<int> dijk(vector<vector<pii>> &adj, int start)
{
    int n = adj.size();
    vector<int> vis(n), dist(n, 1e18);
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
            if(vis[adjnode.second]) continue;
            if(dist[adjnode.second] > dist[curr.second] + adjnode.first)
            {
                dist[adjnode.second] = dist[curr.second] + adjnode.first;
                pq.push({dist[adjnode.second], adjnode.second});
            }
        }
    }
    return dist;
}

void solve()
{
    setIO("apple");
    int m, n, start, dest1, dest2; cin >> m >> n >> start >> dest1 >> dest2; start--; dest1--; dest2--;
    vector<vector<pii>> adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        adj[u].pb({w, v}), adj[v].pb({w, u});
    }
    vector<int> a = dijk(adj, start), b = dijk(adj, dest1), c = dijk(adj, dest2);
    int ans = min({a[dest1] + b[dest2], a[dest2] + c[dest1]});
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
