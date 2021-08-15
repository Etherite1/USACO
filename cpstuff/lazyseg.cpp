template<typename T>
struct lazyseg
{
    T n, neutral = 0;
    vector<T> t, lazy;
    bool range_modif = 0;
 
    void init(int nn)
    {
        n = nn;
        t.resize(4 * n); lazy.resize(4 * n);
    }
 
    T comb(T a, T b)
    {
        return a + b;
    }
 
    T comb2(T a, T b)
    {
        return a + b;
    }
 
    void push(int node, int l, int r)
    {
        if(lazy[node] == 0) return;
        t[node] = comb(t[node], lazy[node] * (range_modif? (r - l + 1) : 1));
        if(l != r)
        {
            lazy[2 * node] = comb(lazy[2 * node], lazy[node]);
            lazy[2 * node + 1] = comb(lazy[2 * node + 1], lazy[node]);
        }
        lazy[node] = 0;
    }
 
    void update(int pos, T val) // 0 indexed
    {
        update(1, 0, n - 1, pos, pos, val);
    }
 
    void update(int l, int r, T val) //[l...r] 0 indexed
    {
        update(1, 0, n - 1, l, r, val);
    }
 
    void update(int node, int l, int r, int tl, int tr, T val)
    {
        push(node, l, r);
        if(l > tr || r < tl) return;
        else if(l >= tl && r <= tr) lazy[node] = comb(lazy[node], val), push(node, l, r);
        else
        {
            int mid = (l + r) / 2;
            update(2 * node, l, mid, tl, tr, val);
            update(2 * node + 1, mid + 1, r, tl, tr, val);
            t[node] = comb2(t[2 * node], t[2 * node + 1]);
        }
    }
 
    T query(int pos) // 0 indexed
    {
        return query(1, 0, n - 1, pos, pos);
    }
 
    T query(int l, int r) //[l...r] 0 indexed
    {
        return query(1, 0, n - 1, l, r);
    }
 
    T query(int node, int l, int r, int tl, int tr)
    {
        push(node, l, r);
        if(l > tr || r < tl) return neutral;
        else if(l >= tl && r <= tr) return t[node];
        else
        {
            int mid = (l + r) / 2;
            T left = query(2 * node, l, mid, tl, tr);
            T right = query(2 * node + 1, mid + 1, r, tl, tr);
            return comb2(left, right);
        }
    }
};