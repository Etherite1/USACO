#include <bits/stdc++.h>
 
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define INF 1e17
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

/*main takeaways of djikstra's algorithm implementation:

priorityqueue of pairs, container of vector, comparator is greater (compares pairs by weight)
set all distances from starting node to infinity except dist[0] = 0
also initialize parent array, parent[i] = parent of ith node on the shortest path

while pq is not empty, loop through the popped element's neighbours
    if visited the popped element already, continue
    if distance from popped element to adjacent element is less than distance to adjacent element:
        we have found a new shortest path, modify distances and parent nodes accordingly

after, to actually obtain the path, we just loop backwards through the parent array from the target element back to original, then reverse

observations:
i assume that when i have a 2d grid i can just create the graph with pair<int, pair<int, int>>, which stands for pair<weight, pair<destX, destY>>
since we are sorting the priorityqueue by weight anyways this will work

*/

void dijkstra(vector<pii> adj[], ll n)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<ll> dist(n, INF);
    dist[0] = 0;
    vector<ll> parent(n, -1);
    pq.push({0, 0});
    vector<bool> v(n);
    
    while(!pq.empty())
    {
        pii top = pq.top(); pq.pop();
        if(v[top.se]) continue;
        v[top.se] = true;
    
        for(int i = 0; i < adj[top.se].size(); i++)
        {
            pii k = adj[top.se][i];
            if(dist[top.se] + k.fi < dist[k.se])
            {
                dist[k.se] = dist[top.se] + k.fi;
                parent[k.se] = top.se;
                pq.push({dist[k.se], k.se});
            }
        }
 
    }
    ll st = n - 1;
    vector<ll> arr = {n};
    while(parent[st] != -1)
    {
        arr.pb(parent[st] + 1);
        st = parent[st];
    }
    if(st == 0)
    {    
        reverse(arr.begin(), arr.end());
        for(auto i : arr) cout << i << " ";
    }
    else cout << "-1" << endl;
    
}

/* main takeaways:
create graph with vector of pairs
adj[i].first = weight
adj[i].second = destination
or vice versa
*/ 

int main()
{
    fastio

    ll n, m;
    cin >> n >> m;
    vector<pii> adj[n];
    for(int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({w, v - 1});
        adj[v - 1].push_back({w, u - 1});
            
    }
    dijkstra(adj, n);
}

