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

int n, m;
ll origdist = 0;
vl dijkstra(vector<vii> adj, bool returndist)
{
    vl par(n, -1), dist(n, 1e18), v(n);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[0] = 0;
    pq.push(mp(0, 0));
    while(!pq.empty())
    {
        pll curr = pq.top(); pq.pop();
        if(v[curr.second]) continue; v[curr.second] = 1;
        for(pll adjnode : adj[curr.second])
        {
            if(v[adjnode.second]) continue;
            if(dist[adjnode.second] > dist[curr.second] + adjnode.first)
            {
                dist[adjnode.second] = dist[curr.second] + adjnode.first;
                par[adjnode.second] = curr.second;
                pq.push(mp(dist[adjnode.second], adjnode.second));
            }
        }
    }
    if(!returndist) origdist = dist[n - 1];
    int end = n - 1;
    vl path; path.pb(n - 1);
    while(par[end] != -1)
    {
        path.pb(par[end]);
        end = par[end];
    }
    reverse(all(path));
    return (returndist? dist : path);
}

void solve()
{
    setIO("rblock");
    cin >> n >> m;
    vector<vii> adj(n);
    rep(i, 0, m)
    {
        int u, v, w; cin >> u >> v >> w;
        adj[u - 1].pb(mp(w, v - 1));
        adj[v - 1].pb(mp(w, u - 1));
    }
    vl path = dijkstra(adj, 0);
    ll ans = 0;
    rep(i, 0, path.size() - 1)
    {
        int u = path[i], v = path[i + 1];
        rep(j, 0, adj[u].size())
        {
            if(adj[u][j].second == v) adj[u][j].first *= 2;
        }
        rep(j, 0, adj[v].size())
        {
            if(adj[v][j].second == u) adj[v][j].first *= 2;
        }
        vl dist = dijkstra(adj, 1);
        ans = max(ans, abs(origdist - dist[n - 1]));
        rep(j, 0, adj[u].size())
        {
            if(adj[u][j].second == v) adj[u][j].first /= 2;
        }
        rep(j, 0, adj[v].size())
        {
            if(adj[v][j].second == u) adj[v][j].first /= 2;
        }
    }
    cout << ans << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
