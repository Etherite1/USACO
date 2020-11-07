// uses Prim's algorithm to find the minimum spanning tree 

vector<int> dist(n, 1e9);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> pq;
vector<bool> v(n);
dist[0] = 0;
pq.push(make_pair(0, 0));
int sum = 0;
while(!pq.empty())
{
    pair<int, int> curr = pq.top(); pq.pop();
    if(v[curr.second]) continue; v[curr.second] = 1;
    sum += dist[curr.second];
    for(pair<int, int> adjnode : adj[curr.second])
    {
        if(adjnode.first < dist[adjnode.second] && !v[adjnode.second]) 
        {
            dist[adjnode.second] = adjnode.first;
            pq.push(adjnode);
        }
    }
}

for(int i = 0; i < n; i++)
    if(!v[i]) 
    {
        cout << "-1\n"; return;
    }
cout << sum << endl;
