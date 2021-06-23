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

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

const int N = 1e5 + 1;
vi adj[N];
bool isfile[N];
int n, filesct = 0, numfiles[N];
ll namelength[N], length[N], best = 1e18;

void dfslength(int node, ll pathlength)
{
    length[node] = pathlength + namelength[node];
    for(auto adjnode : adj[node]) dfslength(adjnode, length[node]);
}

ll dfsfiles(int node)
{
    if(isfile[node]) return 1;
    int ct = 0; for(auto adjnode : adj[node]) ct += dfsfiles(adjnode);
    return numfiles[node] = ct;
}

void dfs(int node, ll dist)
{
    best = min(best, dist);
    for(auto adjnode : adj[node])
    {
        if(isfile[adjnode]) continue;
        ll nd = dist - namelength[adjnode] * numfiles[adjnode] + 3 * (filesct - numfiles[adjnode]);
        dfs(adjnode, nd);
    }
}

void solve()
{
    setIO("dirtraverse");
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string name; int m; cin >> name >> m;
        namelength[i] = sz(name);
        isfile[i] = m == 0;
        while(m--)
        {
            int x; cin >> x; x--;
            adj[i].pb(x);
        }
        if(isfile[i]) filesct++;
        else namelength[i]++;
    }
    namelength[0] = 0;
    dfslength(0, 0);
    ll initlen = 0;
    for(int i = 0; i < n; i++) if(isfile[i]) initlen += length[i];
    best = initlen;
    for(int i = 0; i <= n; i++) numfiles[i] = -1;
    dfsfiles(0); 
    dfs(0, initlen);
    cout << best << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
