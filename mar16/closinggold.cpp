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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353
const int INF = 1e9;

bool cmp()
{
    return 0;
}

struct dsu
{
    vector<int> parent, sz;
    void init(int n)
    {
        parent = vector<int>(n + 1), sz = vector<int>(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }  

    int find(int x)
    {
        if(parent[x] == x) return x;
        else return parent[x] = find(parent[x]);
    }

    void merge(int a, int b)
    {
        int roota = find(a), rootb = find(b);
        if(sz[roota] > sz[rootb]) swap(roota, rootb);
        parent[roota] = rootb; sz[rootb] += sz[roota];
    }
};

int main()
{
    fastio

    if(fopen("closing.in", "r"))
    {
        freopen("closing.in","r",stdin);
        freopen("closing.out","w",stdout);
    }

    int n, m; cin >> n >> m;
    vvi adj(n);
    for(int i = 0; i < m; i++) 
    {
        int u, v; cin >> u >> v;
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }

    vi order(n); for(int i = n - 1; i >= 0; i--) cin >> order[i];
    for(int i = 0; i < n; i++) order[i]--;
    set<int> vis;
    dsu d; d.init(n);

    vb conn(n);
    int comps = 0;
    for(int i = 0; i < n; i++)
    {
        int currfarm = order[i];
        vis.insert(currfarm);
        comps++;
        for(int adjnode : adj[currfarm])
        {
            if(d.find(adjnode) == d.find(currfarm) || vis.find(adjnode) == vis.end()) continue;
            d.merge(adjnode, currfarm); comps--;
        }
        conn[i] = comps <= 1;
    }
    reverse(all(conn));
    for(bool i : conn) cout << (i? "YES" : "NO") << "\n";
}
