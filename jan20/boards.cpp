#include "bits/stdc++.h"

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
#define rsz resize
#define sz(a) ((int)(a).size())

#ifdef Etherite_Local
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.first << ", " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cerr << i << " "; cerr << endl;}
#else
#define DBG1(x)
#define DBG2(x, y)
#define DBG3(x, y, z)
#define DBG4(a, b, c, d)
template<class T> void DBGpair(T a, string s = "") {return;}
template <class T> void DBGvec(vector<T> &a){}
#endif

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
        return min(x, y);
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
        if(ql > r || qr < l) return 1e18;
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


// dp[i] = minimum cost to get to start of board i using end points of board j where end point of j is to bottom left of start of i

struct event
{
    ll x, y, i;
    bool r;

    event(ll xx, ll yy, bool rr, ll ii) {x = xx, y = yy, r = rr; i = ii;}

    bool operator < (const event& o) const
    {
        if(x == o.x) return y < o.y;
        return x < o.x;
    }
};

void solve()
{
    setIO("boards");
    ll n, gsz; cin >> gsz >> n;
    vector<event> a;
    for(int i = 0; i < n; i++)
    {
        int w, x, y, z; cin >> w >> x >> y >> z;
        a.pb(event(w, x, 0, i));
        a.pb(event(y, z, 1, i));
    }
    sort(all(a));
    set<ll> st; for(auto e : a) st.insert(e.y);
    map<ll, ll> cc;
    int idx = 1;
    for(auto i : st) cc[i] = idx, idx++;
    vl dp(n + 10);
    segtree<ll> s; s.init(500000);
    ll ans = 1e12;
    // dp[i] = a[i].x1 + a[i].y1 + min j from [0... n) dp[j] - a[j].x2 - a[j].y2;
    for(auto e : a)
    {
        if(e.r)
        {
            if(s.query(cc[e.y], cc[e.y]) > dp[e.i] - e.x - e.y) s.update(cc[e.y], dp[e.i] - e.x - e.y);
        }
        else
        {
            dp[e.i] = e.x + e.y + s.query(0, cc[e.y]);
        }
    }
    for(auto e : a)
    {
        if(e.r)
        {
            ans = min(ans, dp[e.i] + 2 * gsz - e.x - e.y);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    // cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
