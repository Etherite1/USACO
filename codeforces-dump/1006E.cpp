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
    for(T i : a) cout << i << " ";
    cout << endl;
}

bool cmp()
{
    return 0;
}

vi order, rseg;
vvi adj;

void dfs(int u)
{
    order.pb(u + 1);
    for(int adjnode : adj[u])
    {
        dfs(adjnode);
    }
    rseg[u + 1] = order.size() - 1;
}

void solve()
{
    int n, q; cin >> n >> q;
    adj.resize(n);
    rep(i, 0, n - 1)
    {
        int x; cin >> x; x--;
        adj[x].pb(i + 1);
    }
    rep(i, 0, n) sort(all(adj[i]));
    rseg.resize(n + 1);
    dfs(0);
    vi pos(n + 1);
    rep(i, 0, n) pos[order[i]] = i; 
    rep(i, 0, q)
    {
        int u, k; cin >> u >> k; 
        if(pos[u] + k - 1 > rseg[u]) cout << -1 << endl;
        else
        {
            cout << order[pos[u] + k - 1] << endl;
        }
    }
    // printvec(order);
    // rep(i, 1, n + 1) cout << pos[i] << " "; cout << endl;
    // printvec(rseg);
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
