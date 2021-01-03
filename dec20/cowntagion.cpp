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

vb v;
int ans = 0;
int n;
vvi adj;
void dfs(int u, int par)
{
    for(int adjnode : adj[u])
    {
        if(v[adjnode]) continue;
        v[adjnode] = 1;
        dfs(adjnode, u);
    }
    int currcnt = 1;
    if(par == -1)
    {
        currcnt += adj[u].size();
        ans += adj[u].size();
    }
    else
    {
        currcnt += adj[u].size() - 1;
        ans += adj[u].size() - 1;
    }
    for(int i = 0; i < 20; i++)
    {
        int a = pow(2, i);
        if(a >= currcnt)
        {
            ans += i;
            break;
        }
    }
}

void solve()
{
    cin >> n;
    if(n == 1) 
    {
        cout << "0\n"; return;
    }
    adj.resize(n);
    rep(i, 0, n - 1)
    {
        int u, v; cin >> u >> v;
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }
    int c = 0;
    v.resize(n); v[c] = 1;
    dfs(c, -1);
    cout << ans << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
