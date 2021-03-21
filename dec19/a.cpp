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

struct lca_lift
{
    int n, l, timer;
    vector<int> tin, tout;
    vector<vector<int>> up, adj;

    void dfs(int v, int p)
    {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i) up[v][i] = up[up[v][i-1]][i-1];
        for (int u : adj[v]) if (u != p) dfs(u, v);
        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v) {return tin[u] <= tin[v] && tout[u] >= tout[v];}

    int lca(int u, int v)
    {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = l; i >= 0; --i) if (!is_ancestor(up[u][i], v)) u = up[u][i];
        return up[u][0];
    }

    void init(int nn, vvi ad) {n = nn; adj = ad;}

    void preprocess(int root) 
    {
        tin.resize(n); tout.resize(n);
        timer = 0; l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        dfs(root, root);
    }
};

struct query
{
    int u, v, c;
    query(int uu, int vv, int cc) {u = uu, v = vv, c = cc;}
};

vector<map<int, int>> cnt;
vi colors;
vector<set<int>> willq;
vvi adj;
map<int, int> tot;

void dfs(int curr, int par)
{
    tot[colors[curr]]++;
    for(int i : willq[curr]) cnt[curr].insert(mp(i, tot[i]));
    for(int adjnode : adj[curr])
    {
        if(adjnode == par) continue;
        dfs(adjnode, curr);
    }
    tot[colors[curr]]--;
}

void solve()
{
    setIO("milkvisits");
    int n, m; cin >> n >> m;
    cnt.rsz(n); colors.rsz(n); adj.rsz(n); willq.rsz(n);
    for(auto &i : colors) cin >> i;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    lca_lift tree; tree.init(n, adj);
    tree.preprocess(0);
    vector<query> qs;
    while(m--)
    {
        int u, v, c; cin >> u >> v >> c; u--; v--;
        qs.pb(query(u, v, c));
        willq[u].insert(c);
        willq[v].insert(c);
        willq[tree.lca(u, v)].insert(c);
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++)
    {
        DBG1(i);
        for(auto j : cnt[i]) DBGpair(j);
    }
    vb ans(qs.size());
    for(int i = 0; i < qs.size(); i++)
    {
        query q = qs[i];
        if(cnt[q.u][q.c] + cnt[q.v][q.c] - 2 * cnt[tree.lca(q.u, q.v)][q.c] + (colors[tree.lca(q.u, q.v)] == q.c) > 0) ans[i] = 1;
        else ans[i] = 0;
    }
    for(int i : ans) cout << i;
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
