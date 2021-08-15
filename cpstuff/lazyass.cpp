struct lz
{
    long long t, val; 
};

template<typename T>
struct lazyseg
{
    T n, neutral = 0;
    vector<T> t;
    vector<lz> lazy;
    bool range_modif = 0;
 
    void init(int nn)
    {
        n = nn;
        t.resize(4 * n); lazy.resize(4 * n);
        for(auto &i : lazy) i = {0, 0};
    }
 
    T comb(T a, T b)
    {
        return a + b;
    }

    lz mergelazy(lz a, lz b)
    {
        if(b.t == 2) 
        {
            if(a.t) return {a.t, a.val + b.val};
            else return {2, a.val + b.val};
        }
        if(b.t) return b;
        else return a;
    }

    void push(int i, int l, int r)
    {
        if(lazy[i].t == 1) t[i] = lazy[i].val * (r - l + 1);
        else if(lazy[i].t == 2) t[i] += lazy[i].val * (r - l + 1);
        if(l != r)
        {
            lazy[2 * i] = mergelazy(lazy[2 * i], lazy[i]);
            lazy[2 * i + 1] = mergelazy(lazy[2 * i + 1], lazy[i]);
        }
        lazy[i] = {0, 0};
    }
    
    T query(int i, int l, int r, int tl, int tr)
    {
        push(i, l, r);
        if(l > tr || r < tl) return neutral;
        if(l >= tl && r <= tr) return t[i];
        int mid = (l + r) / 2;
        return comb(query(2 * i, l, mid, tl, tr), query(2 * i + 1, mid + 1, r, tl, tr));
    }

    T query(int l, int r) // 0-indexed [l, r]
    {
        return query(1, 0, n - 1, l, r);
    }

    T query(int i) // 0-indexed point query
    {
        return query(1, 0, n - 1, i, i);
    }

    void update(int i, int l, int r, int tl, int tr, lz x)
    {
        push(i, l, r);
        if(l > tr || r < tl) return;
        if(l >= tl && r <= tr)
        {
            lazy[i] = mergelazy(lazy[i], x);
            push(i, l, r); 
            return;
        }
        int mid = (l + r) / 2;
        update(2 * i, l, mid, tl, tr, x);
        update(2 * i + 1, mid + 1, r, tl, tr, x);
        t[i] = comb(t[2 * i], t[2 * i + 1]);
    }

    void update(int l, int r, int val, int type) // 1 is assignment, 2 is add, 0-indexed on [l, r]
    {
        lz c = {type, val};
        update(1, 0, n - 1, l, r, c);
    }

    void update(int i, int val, int type) // 0 indexed point update
    {
        lz c = {type, val};
        update(1, 0, n - 1, i, i, c);
    }

};