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
int MOD = 1e9 + 7; //998244353
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

bool within(map<int, int> &a, int b) {return a.find(b) != a.end();}

void solve()
{
    ll n, k, m; cin >> n >> k >> m;
    vii swaps(k);
    for(auto &i : swaps) cin >> i.first >> i.second, i.first--, i.second--;
    vi to(n); iota(all(to), 0);
    vector<set<pii>> s(n); for(int i = 0; i < n; i++) s[i].insert({i, 0});
    vector<set<int>> seen(n); for(int i = 0; i < n; i++) seen[i].insert(i);
    for(int j = 1; j <= k; j++)
    {
        pii i = swaps[j - 1];
        swap(to[i.first], to[i.second]);
        if(seen[to[i.first]].find(i.first) == seen[to[i.first]].end()) s[to[i.first]].insert({i.first, j}), seen[to[i.first]].insert(i.first);
        if(seen[to[i.second]].find(i.second) == seen[to[i.second]].end()) s[to[i.second]].insert({i.second, j}), seen[to[i.second]].insert(i.second);
    }      
    vi vis(n), ans(n); vvi cycles;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            vi c;
            int curr = i;
            while(!vis[curr])
            {
                c.pb(curr);
                vis[curr] = 1;
                curr = to[curr];
            }
            cycles.pb(c);
        }
    }  
    for(auto c : cycles)
    {
        reverse(all(c));
        if(sz(c) <= m / k)
        {
            set<int> x;
            for(auto i : c) for(auto j : s[i]) x.insert(j.first);
            for(auto i : c) ans[i] = sz(x);
        }
        else if(m / k == 0)
        {
            for(auto i : c) for(auto j : s[i]) if(j.second <= (m % k)) ans[i]++;
        }
        else
        {
            map<int, int> run;
            int pl = 0, pr = m / k - 1;
            for(int i = pl; i <= pr; i++)
            {
                for(auto j : s[c[i]]) run[j.first]++;
            }
            bool flag = 0;
            while(true)
            {
                if(pl == 0 && flag) break;
                int nx = (pr + 1) % sz(c);
                flag = 1;
                ans[c[pl]] = sz(run);
                for(auto i : s[c[nx]]) if(!within(run, i.first) && i.second <= (m % k)) ans[c[pl]]++;
                for(auto i : s[c[pl]])
                {
                    run[i.first]--; 
                    if(run[i.first] == 0) run.erase(i.first);
                }
                pl++; pr++; pl %= sz(c); pr %= sz(c);
                for(auto i : s[c[pr]]) run[i.first]++; 
            }
        }
    }
    for(auto i : ans) cout << i << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
