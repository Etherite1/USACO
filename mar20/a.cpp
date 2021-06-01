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

const int N = 2e5 + 10;
vi adj[N], merged[N], par(N), ccnt(N);
queue<int> q;

void solve()
{
    setIO("fcolor");
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].pb(v);
    }
    for(int i = 0; i < n; i++)
    {
        par[i] = i; merged[i].pb(i);
        if(sz(adj[i]) > 1) q.push(i);
    }
    while(!q.empty())
    {
        int c = q.front();
        if(sz(adj[c]) <= 1) {q.pop(); continue;}
        int curr = adj[c].back(); adj[c].pop_back();
        if(par[curr] != par[adj[c].back()]) 
        {
            int x = par[curr], y = par[adj[c].back()];
            if(sz(merged[x]) < sz(merged[y])) swap(x, y);
            for(auto i : merged[y]) {par[i] = x; merged[x].pb(i);}
            for(auto i : adj[y]) adj[x].pb(i);
            merged[y].clear();
            adj[y].clear();
            if(sz(adj[x]) > 1) q.push(x);
        }
    }
    int color = 0;
    for(int i = 0; i < n; i++)
    {
        if(!ccnt[par[i]]) ccnt[par[i]] = ++color;
        cout << ccnt[par[i]] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
