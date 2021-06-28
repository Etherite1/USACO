#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define plpll pair<long long, pair<long long, long long>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vii vector<pii>
#define vll vector<pll>
#define vl vector<long long>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define endl "\n"
#define rsz resize
#define sz(a) ((int)(a).size())

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update > oset; // find_by_order, order_of_key
#define fbo find_by_order
#define ook order_of_key
#define bitcount __builtin_popcount

#ifdef Etherite_Local
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
#define DBG5(a, b, c, d, e) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << " " << (#e) << ": " << a << " " << b << " " << c << " " << d << " " << e << endl;
#define DBG6(a, b, c, d, e, f) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << " " << (#e) << " " << (#f) << ": " << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.first << ", " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cerr << i << " "; cerr << endl;}
template <class T> void DBGset(set<T> a){for(T i : a) cerr << i << " "; cerr << endl;}
mt19937 rnd(228);
#else
#define DBG1(x)
#define DBG2(x, y)
#define DBG3(x, y, z)
#define DBG4(a, b, c, d)
#define DBG5(a, b, c, d, e)
#define DBG6(a, b, c, d, e, f)
template<class T> void DBGpair(T a, string s = "") {return;}
template <class T> void DBGvec(vector<T> &a){}
template <class T> void DBGset(set<T> &a){}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353
const ll INF = 1e9;

ll add(ll a, ll b) {return (a + b) % MOD;}
ll sub(ll a, ll b)
{
    ll x = a - b;
    while(x < 0) x += MOD;
    return x;
}
ll mul(ll a, ll b) {return (a * b) % MOD;}
// ll divi(ll a, ll b) {return (a * modinv(b, MOD)) % MOD;}

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

template<typename T>
struct minseg
{
    T n, neutral = 1e18;
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
        return min(a, b);
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

template<typename T>
struct sumseg
{
    T n, neutral = 0;
    vector<T> t, lazy;
    bool range_modif = 1;
 
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

void solve()
{
    setIO("haybales");
    int n, q; cin >> n >> q;
    minseg<ll> mn; mn.init(n);
    sumseg<ll> sum; sum.init(n);
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x; mn.update(i, x); sum.update(i, x);
    }
    while(q--)
    {
        char t; int l, r; cin >> t >> l >> r; l--; r--;
        if(t == 'M')
        {
            cout << mn.query(l, r) << endl;
        }
        else if(t == 'P')
        {
            int val; cin >> val;
            mn.update(l, r, val);
            sum.update(l, r, val);
        }
        else
        {
            cout << sum.query(l, r) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    // cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
