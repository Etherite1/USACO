#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vii vector<pii>
#define vll vector<pll>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vl vector<long long>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.first << ", " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cerr << i << " "; cerr << endl;}

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
template<typename T> 
struct mintree
{
    vector<T> tree, arr;
    int size;

    void print()
    {
        for(T i : tree) cout << i << " ";
        cout << endl;
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
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    T query(int l, int r) // 0 indexed querying
    {
        return query(l, r, 0, size - 1, 0);
    }

    T query(int ql, int qr, int l, int r, int node)
    {
        if(ql <= l && qr >= r) return tree[node];
        if(ql > r || qr < l) return 1e18;
        int mid = (l + r) / 2;
        return min(query(ql, qr, l, mid, 2 * node + 1), query(ql, qr, mid + 1, r, 2 * node + 2));
    }
};

template<typename T> 
struct mxtree
{
    vector<T> tree, arr;
    int size;

    void print()
    {
        for(T i : tree) cout << i << " ";
        cout << endl;
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
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    T query(int l, int r) // 0 indexed querying
    {
        return query(l, r, 0, size - 1, 0);
    }

    T query(int ql, int qr, int l, int r, int node)
    {
        if(ql <= l && qr >= r) return tree[node];
        if(ql > r || qr < l) return 0;
        int mid = (l + r) / 2;
        return max(query(ql, qr, l, mid, 2 * node + 1), query(ql, qr, mid + 1, r, 2 * node + 2));
    }
};

bool cmp(pll a, pll b)
{
    return a.second < b.second;
}

void solve()
{
    setIO("split");
    int n; cin >> n;
    vll a(n); for(auto &i : a) cin >> i.first >> i.second;
    sort(all(a), cmp);  
    vl ys; for(auto i : a) ys.pb(i.first);    
    mxtree<ll> mx; mintree<ll> mn;
    mx.init(ys); mn.init(ys);
    ll ans = 2e18;
    for(int i = 0; i < n - 1; i++)
    {
        ll dxleft = a[i].second - a[0].second, dxright = a[n - 1].second - a[i + 1].second;
        ll dyleft = mx.query(0, i) - mn.query(0, i), dyright = mx.query(i + 1, n - 1) - mn.query(i + 1, n - 1);
        ans = min(ans, dxleft * dyleft + dxright * dyright);
    }
    // cout << (mx.query(0, n - 1) - mn.query(0, n - 1)) * (a[n - 1].first - a[0].first) - ans << endl; 
    sort(all(a));
    vl minright(n, 1e9 + 1), mxright(n);
    ll minseen = 1e9 + 1, mxseen = 0;

    minright[n - 1] = a[n - 1].second; mxright[n - 1] = a[n - 1].second;
    for(int i = n - 1; i > 0; i--) minright[i - 1] = min(minright[i], a[i - 1].second);
    for(int i = n - 1; i > 0; i--) mxright[i - 1] = max(mxright[i], a[i - 1].second);
    // ll ans = 2e18;
    ll onemin = 1e9 + 1, onemx = 0;
    for(int i = 0; i < n - 1; i++)
    {
        onemin = min(onemin, a[i].second); onemx = max(onemx, a[i].second);
        minseen = min(minseen, a[i].second); mxseen = max(mxseen, a[i].second);
        ll left = (a[i].first - a[0].first) * (mxseen - minseen);
        ll right = (a[n - 1].first - a[i + 1].first) * (mxright[i + 1] - minright[i + 1]);
        // DBG4(i, left, right, left + right);
        // DBGpair(a[i]);
        ans = min(ans, left + right);
    }   
    onemin = min(onemin, a[n - 1].second); onemx = max(onemx, a[n - 1].second);
    // DBGvec(minright);
    // DBGvec(mxright);
    cout << ((a[n - 1].first - a[0].first) * (onemx - onemin)) - ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
