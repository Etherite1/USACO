/*
returns sum of minimum spanning tree in O(v^2 * logv^2) time, with v as number of vertices
a vector of pair<int, pair<int, int>> must be initialized, this represents pair<weight, pair<endpoint, endpoint>>
also requires a DSU to function (code provided in other file)
*/

dsu d; d.init(n);

ll cost = 0;
for(pipii i : edges)
{
    int a = i.second.first, b = i.second.second;
    if(d.find(a) == d.find(b)) continue;
    else
    {
        cost += i.first;
        d.merge(a, b);
    }
}
