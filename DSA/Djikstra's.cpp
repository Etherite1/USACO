#include <bits/stdc++.h>
 
using namespace std;


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
i assume that when i have a 2d grid i can just create the graph with pair<int, pair<pii, pii>>, which stands for pair<weight, pair<destX, destY>>
since we are sorting the priorityqueue by weight anyways this will work

*/

void dijkstra(vector<vector<pair<int, int>>> adj, long long n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<long long> dist(n, 1e17);
    dist[0] = 0;
    vector<long long> parent(n, -1);
    pq.push({0, 0});
    vector<bool> v(n);
    
    while(!pq.empty())
    {
        pair<int, int> top = pq.top(); pq.pop();
        if(v[top.second]) continue;
        v[top.second] = true;
    
        for(int i = 0; i < adj[top.second].size(); i++)
        {
            pair<int, int> k = adj[top.second][i];
            if(dist[top.second] + k.first < dist[k.second])
            {
                dist[k.second] = dist[top.second] + k.first;
                parent[k.second] = top.second;
                pq.push({dist[k.second], k.second});
            }
        }
 
    }
    long long st = n - 1;
    vector<long long> arr = {n};
    while(parent[st] != -1)
    {
        arr.push_back(parent[st] + 1);
        st = parent[st];
    }
    if(st == 0)
    {    
        reverse(arr.begin(), arr.end());
        for(long long i : arr) cout << i << " ";
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
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++)
    {
        long long  u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({w, v - 1});
        adj[v - 1].push_back({w, u - 1});
            
    }
    dijkstra(adj, n);
}

