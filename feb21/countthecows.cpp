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

ll pow3[40];

// counts number of cows in d * d grid if the starting position is x
ll f(ll x, ll d) 
{
    if(d == 0) return 1;
    if(x == pow3[d - 1]) return 0;
    if(x < pow3[d - 1]) return 3 * f(x, d - 1);
    else if(x >= 2 * pow3[d - 1]) return f(x % pow3[d - 1], d - 1);
    else return f(2 * pow3[d - 1] - x, d - 1);
}

ll g(ll x, ll y, ll d)
{
    if(x < y) swap(x, y);
    // DBG3(x, y, d);
    if(d == 0) return 1;
    if(x - y == pow3[d - 1]) return 0;
    if(x - y < pow3[d - 1])
    {
        ll nx = x, ny = y, times = 0;
        // while(ny >= pow3[d - 1]) nx -= pow3[d - 1], ny -= pow3[d - 1], times++;
        if(x < pow3[d - 1] - 1) times = 0;
        else if(x < 2 * pow3[d - 1] - 1) times = 1;
        else times = 2;
        nx -= times * pow3[d - 1], ny -= times * pow3[d - 1];
        // assert(nx >= 0 && ny >= 0);
        // DBG4(d, nx, ny, times);
        ll f1 = f(nx - ny, d - 1);
        ll f2 = 0;
        if(ny >= 0) f2 = g(nx, ny, d - 1); 
        // DBG3(d, times * f1, f2);
        return times * f1 + f2;
    }
    else if(x - y < 2 * pow3[d - 1])
    {
        if(x < 2 * pow3[d - 1]) return 0;
        return g(y, x % pow3[d - 1], d);
    }
    else
    {
        return g(x % pow3[d - 1], y, d);
    }
}

ll getans(ll x, ll y)
{
    if(x < 0 || y < 0) return 0;
    // return g(x, y, 3);
    return g(x, y, 39);
}

void solve()
{
    ll d, x, y; cin >> d >> x >> y;
    ll ex = x + d, ey = y + d;
    cout << getans(ex, ey) - getans(x - 1, y - 1) << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    pow3[0] = 1;
    for(int i = 1; i < 40; i++) pow3[i] = pow3[i - 1] * 3;

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) solve();

    return 0;
}
