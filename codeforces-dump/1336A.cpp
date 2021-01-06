#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vb vector<bool>
#define vl vector<long long>
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pf push_front
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for(int (i) = (a); (i) < (b); (i)++) 
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353
const int INF = 1e9;

template <class T> void printvec(vector<T> a)
{
    for(T i : a) cout << i << " ";
    cout << endl;
}

bool cmp()
{
    return 0;
}

vi sizes(200000, 1), dep(200000), cnts; vb v(200000);
void dfs(vvi adj, int curr)
{
    for(int adjnode : adj[curr])
    {
        if(v[adjnode]) continue; v[adjnode] = 1;
        dep[adjnode] = dep[curr] + 1;
        dfs(adj, adjnode);
        sizes[curr] += sizes[adjnode];
    }
    cnts.pb(dep[curr] - sizes[curr] + 1);
}

void solve()
{
    int n, k; cin >> n >> k;
    vvi adj(n);
    rep(i, 0, n - 1)
    {
        int l, r; cin >> l >> r; l--; r--;
        adj[l].pb(r);
        adj[r].pb(l);
    }   
    v[0] = 1;
    dfs(adj, 0);
    sort(rall(cnts));
    int ans = 0; rep(i, 0, k) ans += cnts[i];
    cout << ans << endl;
}

int main()
{
    fastio

    if(fopen("file.in", "r"))
    {
        freopen("file.in","r",stdin);
        freopen("file.out","w",stdout);
    }

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
