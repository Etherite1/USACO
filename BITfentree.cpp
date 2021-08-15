struct bit 
{
    vector<long long> tree;
    bit(int n) {tree = vector<long long>(n + 5, 0);}

    long long rsq(int idx) 
    {
        long long sum = 0; 
        while(idx > 0)
        {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum; 
    }

    long long rsq(int a, int b) // 0 based indexing range query on [a, b]
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
