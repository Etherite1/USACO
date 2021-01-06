#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vl vector<long long>
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pf push_front
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i, begin, end) for(int i = begin; i < end; i++)
#define brep(i, end, begin) for(int i = end; i > begin; i--)
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()
#define watch(x) cout << (#x) << " is " << (x) << endl

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

template <class T> void printvec(vector<T> a)
{
    for(T i : a) cerr << i << " ";
    cerr << endl;
}

bool cmp()
{
    return 0;
}
int n, m;
vvi adj;
vi cat;
vb v;
int ans = 0;

void dfs(int curr, int cnt)
{
    // cout << "Curr " << curr << " Cnt " << cnt << endl;
    if(cnt > m) return;
    bool leaf = 1;
    for(int adjnode : adj[curr])
    {
        if(v[adjnode]) continue;
        v[adjnode] = 1; leaf = 0;
        dfs(adjnode, (cat[adjnode]? cnt + 1 : 0));
    }
    if(leaf) ans++;
}

void solve()
{
    cin >> n >> m;
    adj.resize(n);
    cat.resize(n);
    v.resize(n);
    rep(i, 0, n) cin >> cat[i];
    rep(i, 0, n - 1)
    {
        int u, v; cin >> u >> v;
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }
    v[0] = 1;
    dfs(0, cat[0]);
    cout << ans << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
