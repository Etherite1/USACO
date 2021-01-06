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

void solve()
{
    int n, m, s; cin >> n >> m >> s;
    vector<vii> adj(n);
    vector<pipii> edges(m);
    rep(i, 0, m)
    {
        int u, v, w; cin >> u >> v >> w;
        adj[u - 1].pb(mp(w, v - 1));
        adj[v - 1].pb(mp(w, u - 1));
        edges[i] = mp(w, mp(u - 1, v - 1));
    }
    int l; cin >> l; s--;

    vb v(n); vl dist(n, 1e18);
    dist[s] = 0;
    priority_queue<pii, vii, greater<pii>> pq;
    pq.push(mp(0, s));
    while(!pq.empty())
    {
        pii curr = pq.top(); pq.pop();
        if(v[curr.second]) continue; v[curr.second] = 1;
        for(pii adjnode : adj[curr.second])
        {
            if(v[adjnode.second]) continue;
            if(dist[adjnode.second] > dist[curr.second] + adjnode.first)
            {
                dist[adjnode.second] = dist[curr.second] + adjnode.first;
                pq.push(mp(dist[adjnode.second], adjnode.second));
            }
        }
    }
    int cnt = 0;
    for(ll i : dist) if(i == l) cnt++;
    for(pipii i : edges)
    {
        pii curr = i.second; ll w = i.first;
        int u = curr.first, v = curr.second;
        if(dist[u] < l && l - dist[u] < w && w - l + dist[u] + dist[v] > l) cnt++;
        if(dist[v] < l && l - dist[v] < w && w - l + dist[u] + dist[v] > l) cnt++;
        if(dist[u] < l && dist[v] < l && w - l + dist[u] + dist[v] == l) cnt++;
    }
    cout << cnt << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
