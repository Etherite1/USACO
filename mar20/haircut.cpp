#include "bits/stdc++.h"

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
mt19937 rnd(228);
#else
#define DBG1(x)
#define DBG2(x, y)
#define DBG3(x, y, z)
#define DBG4(a, b, c, d)
template<class T> void DBGpair(T a, string s = "") {return;}
template <class T> void DBGvec(vector<T> &a){}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
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

void solve()
{
    setIO("haircut");
    int n; cin >> n;
    vl a(n); for(auto &i : a) cin >> i;
    lazyseg<ll> s; s.init(n + 10);
    vl invcount(n + 10);
    for(int i = 0; i < n; i++)
    {
        invcount[a[i]] += s.query(a[i] + 1, n);
        s.update(a[i], 1);
    }
    DBGvec(invcount);
    vl pref(n + 10);
    for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + invcount[i - 1];
    for(int i = 0; i < n; i++) cout << pref[i] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
