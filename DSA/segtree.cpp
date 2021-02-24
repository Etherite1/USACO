// performs range-based queries on an array
// segtree.init() - initializes the segtree with the vector "a"
// segtree.query() - queries the range [l, r] with 0 indexing
// segtree.update() - performs point-update on the tree, 0 indexing

template<typename T> 
struct segtree
{
    vector<T> tree, arr;
    int size;

    void print()
    {
        for(T i : tree) cout << i << " ";
        cout << endl;
    }
    
    void init(int n)
    {
        size = n;
        tree = vector<T>(4 * n);
    }

    T comb(T x, T y)
    {
        return x + y;
    }

    void init(vector<T> a)
    {
        arr = a;
        size = a.size();
        tree = vector<T>(4 * size);
        build(0, a.size() - 1, 0);
    }

    void build(int l, int r, int node)
    {
        if(l == r) 
        {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, 2 * node + 1);
        build(mid + 1, r, 2 * node + 2);
        tree[node] = comb(tree[2 * node + 1], tree[2 * node + 2]);
    }

    T query(int l, int r) // 0 indexed querying
    {
        return query(l, r, 0, size - 1, 0);
    }

    T query(int ql, int qr, int l, int r, int node)
    {
        if(ql <= l && qr >= r) return tree[node];
        if(ql > r || qr < l) return 0; // 1e9/1e18 if min
        int mid = (l + r) / 2;
        return comb(query(ql, qr, l, mid, 2 * node + 1), query(ql, qr, mid + 1, r, 2 * node + 2));
    }
};
