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

struct edge
{
    int u, v, ca, cb;
};

const int N = 10050;
vector<edge> adj[N];
vector<int> dista(N, 1e9), distb(N, 1e9), distc(N, 1e9), vis(N);

void solve()
{
    setIO("gpsduel");
    int n, m; cin >> n >> m;
    dista[n] = 0; distb[n] = 0; distc[n] = 0;
    for(int i = 0; i < m; i++)
    {
        int u, v, ca, cb; cin >> u >> v >> ca >> cb;
        adj[v].pb({v, u, ca, cb});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, n});
    while(!pq.empty())
    {
        pii curr = pq.top(); pq.pop();
        vis[curr.second] = 1;
        for(auto adjnode : adj[curr.second])
        {
            if(vis[adjnode.v]) continue;
            if(dista[adjnode.v] > dista[curr.second] + adjnode.ca)
            {
                dista[adjnode.v] = dista[curr.second] + adjnode.ca;
                pq.push({dista[adjnode.v], adjnode.v});
            }
        }
    }
    for(auto &i : vis) i = 0;
    pq.push({0, n});
    while(!pq.empty())
    {
        pii curr = pq.top(); pq.pop();
        vis[curr.second] = 1;
        for(auto adjnode : adj[curr.second])
        {
            if(vis[adjnode.v]) continue;
            if(distb[adjnode.v] > distb[curr.second] + adjnode.cb)
            {
                distb[adjnode.v] = distb[curr.second] + adjnode.cb;
                pq.push({distb[adjnode.v], adjnode.v});
            }
        }
    }
    // for(int i = 1; i <= n; i++) cout << dista[i] << " " << distb[i] << endl;
    for(auto &i : vis) i = 0;
    pq.push({0, n});
    while(!pq.empty())
    {
        pii curr = pq.top(); pq.pop();
        vis[curr.second] = 1;
        for(auto adjnode : adj[curr.second])
        {
            if(vis[adjnode.v]) continue;
            int cost = 0;
            if(dista[curr.second] + adjnode.ca > dista[adjnode.v]) cost++;
            if(distb[curr.second] + adjnode.cb > distb[adjnode.v]) cost++;
            if(distc[curr.second] + cost < distc[adjnode.v])
            {
                distc[adjnode.v] = distc[curr.second] + cost;
                pq.push({distc[adjnode.v], adjnode.v});
            }
        }
    }
    cout << distc[1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
