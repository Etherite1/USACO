/*

*******************
DSU IMPLEMENTATION
*******************

tests connectivity among pairwise edges in O(a(n)) time
functions:
init(n) - initializes dsu with n nodes
find(x) - returns root of the tree of node x
merge(x, y) - merges the sets of x and y, which basically connects the components
*/

struct dsu
{
    vector<int> parent, sz;
    void init(int n)
    {
        parent = vector<int>(n + 1), sz = vector<int>(n + 1, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }  

    int find(int x)
    {
        if(parent[x] == x) return x;
        else return parent[x] = find(parent[x]);
    }

    void merge(int a, int b)
    {
        int roota = find(a), rootb = find(b);
        if(sz[roota] > sz[rootb]) swap(roota, rootb);
        parent[roota] = rootb; sz[rootb] += sz[roota];
    }
};

/*
***************************
edges comparator (minimum)
***************************
*/

bool cmp(pipii a, pipii b)
{
    return a.first < b.first;
}

/*
********************
Kruskal's algorithm
********************

returns sum of minimum spanning tree in O(v^2 * logv^2) time, with v as number of vertices
a vector of pair<int, pair<int, int>> must be initialized, this represents pair<weight, pair<endpoint, endpoint>>
also requires a DSU to function (code above)
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
