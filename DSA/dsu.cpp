struct dsu
{
    vector<int> parent, sz;

    void init(int n)
    {
        parent = vector<int>(n + 1);
        sz = vector<int>(n + 1);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    
    int find(int x)
    {
        if(parent[x] == x) return x;
        else
        {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    void merge(int a, int b)
    {
        int roota = find(a), rootb = find(b);
        if(sz[roota] > sz[rootb]) swap(roota, rootb);
        parent[roota] = rootb;
        sz[rootb] += sz[roota];
    }

};
