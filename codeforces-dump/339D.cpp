#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vl vector<long long>
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pf push_front
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i, begin, end) for(int i = begin; i < end; i++)
#define brep(i, end, begin) for(int i = end; i > begin; i--)
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()
#define watch(x) cout << (#x) << " is " << (x) << endl

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353
const ll INF = 1e9;

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

template <class T> void printvec(vector<T> a)
{
    for(T i : a) cout << i << " ";
    cout << endl;
}

bool cmp()
{
    return 0;
}

template<typename T> 
struct segtree
{
    vector<T> tree, arr;
    int size, n;

    void init(vector<T> a, int nn)
    {
        arr = a;
        size = a.size();
        tree = vector<T>(4 * size);
        n = nn;
        build(0, a.size() - 1, 0, n % 2 == 0);
    }

    void build(int l, int r, int node, bool x)
    {
        if(l == r) 
        {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, 2 * node + 1, !x);
        build(mid + 1, r, 2 * node + 2, !x);
        tree[node] = (x? tree[2 * node + 1] ^ tree[2 * node + 2] : tree[2 * node + 1] | tree[2 * node + 2]);
    }

    T query() // 0 indexed querying
    {
        return tree[0];
    }

    void update(int idx, T nval) // 0 indexed updating
    {
        update(0, 1, size, idx + 1, nval, n % 2 == 0);
    }

    void update(int node, int l, int r, int pos, T nval, bool x)
    {
        if(l == r) tree[node] = nval;
        else
        {
            int mid = (l + r) / 2;
            if(pos <= mid) update(node * 2 + 1, l, mid, pos, nval, !x);
            else update(node * 2 + 2, mid + 1, r, pos, nval, !x);
            tree[node] = (x? tree[node * 2 + 1] ^ tree[node * 2 + 2] : tree[node * 2 + 1] | tree[node * 2 + 2]);
        }
    }
};

void solve()
{
    int n, m; cin >> n >> m;
    vl a(1 << n);
    rep(i, 0, 1 << n) cin >> a[i];
    segtree<ll> s; s.init(a, n);
    rep(i, 0, m)
    {
        int l, r; cin >> l >> r;
        s.update(l - 1, r);
        cout << s.query() << endl;
    }
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
