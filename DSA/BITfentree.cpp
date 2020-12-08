struct bit 
{
    vl tree;
    bit(int n) {tree = vl(n + 5, 0);}

    ll rsq(int idx) 
    {
        ll sum = 0; 
        while(idx > 0)
        {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum; 
    }

    ll rsq(int a, int b) // 1 based indexing range query
    {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); 
    }

    void upd(int idx, int val) // 1 based indexing point update
    {
        while(idx < tree.size() - 1)
        {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
};
