#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define endl "\n"
#define pll pair<ll, ll>

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

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
        return max(x, y);
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
    
    void update(int idx, T nval) // 0 indexed updating
    {
        update(0, 1, size, idx + 1, nval);
    }
    void update(int node, int l, int r, int pos, T nval)
    {
        if(l == r) tree[node] = nval;
        else
        {
            int mid = (l + r) / 2;
            if(pos <= mid) update(node * 2 + 1, l, mid, pos, nval);
            else update(node * 2 + 2, mid + 1, r, pos, nval);
            tree[node] = comb(tree[node * 2 + 1], tree[node * 2 + 2]);
        }
    }
};

void solve()
{
    setIO("crowded");
    ll n, d; cin >> n >> d;
    vector<pll> a(n);
    for(auto &i : a) cin >> i.first >> i.second;
    sort(a.begin(), a.end());
    segtree<ll> s; s.init(n);
    for(int i = 0; i < n; i++) s.update(i, a[i].second);   
    vector<int> x; for(auto i : a) x.pb(i.first);
    int ans = 0;
    for(int i = 1; i < n - 1; i++)
    {
        int idx = lower_bound(x.begin(), x.end(), x[i] - d) - x.begin();
        int idx2 = upper_bound(x.begin(), x.end(), x[i] + d) - x.begin() - 1;
        ll mxleft = s.query(idx, i - 1), mxright = s.query(i + 1, idx2);
        // cout << mxleft << " " << mxright << endl;
        if(mxleft >= a[i].second * 2 && mxright >= a[i].second * 2) ans++;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
