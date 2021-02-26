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
#define rsz resize
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

vi a;
int n;
vvi adj;

void dfs(int curr, int par, vb &v, vi &b)
{
    v[curr] = 1;
    if(par != -1) b[curr] = (b[curr] + 1) % 12;
    for(auto adjnode : adj[curr])
    {
        if(v[adjnode]) continue;
        dfs(adjnode, curr, v, b);
        b[curr] = (b[curr] + 1) % 12;
    }
    if(par == -1) return;
    int diff = 11 - b[curr];
    b[curr] = 11;
    b[par] = (b[par] + diff) % 12;
}

bool f(int node)
{
    vi b = a;
    vb v(n);
    dfs(node, -1, v, b);
    // DBG1(node);
    // DBGvec(b);
    return b[node] == 11 || b[node] == 0;
}

void solve()
{
    setIO("clocktree");
    cin >> n;
    a.rsz(n); for(auto &i : a) cin >> i, i--;
    adj.rsz(n);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(f(i)) cnt++;
    }
    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
