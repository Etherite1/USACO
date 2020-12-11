// performs range queries and point updates on a binary indexed tree
// all updates and queries are 0 based indexed
// verified by SPOJ fentree

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

    ll rsq(int a, int b) // 0 based indexing range query
    {
        a++; b++;
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); 
    }

    void upd(int idx, int val) // 0 based indexing point update
    {
        idx++;
        while(idx < tree.size() - 1)
        {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
};
