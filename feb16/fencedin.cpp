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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()
#define vll vector<pll>

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

struct dsu
{
    vector<vector<pii>> parent; vvi sz;
    void init(int n, int m)
    {
        parent = vector<vii>(n + 1, vii(m + 1)), sz = vector<vi>(n + 1, vi(m + 1, 1));
        for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) parent[i][j] = {i, j};
    }  

    pii find(pii x)
    {
        if(parent[x.first][x.second] == x) return x;
        else return parent[x.first][x.second] = find(parent[x.first][x.second]);
    }

    void merge(pii a, pii b)
    {
        pii roota = find(a), rootb = find(b);
        if(sz[roota.first][roota.second] > sz[rootb.first][rootb.second]) swap(roota, rootb);
        parent[roota.first][roota.second] = rootb; sz[rootb.first][rootb.second] += sz[roota.first][roota.second];
    }
};

void solve()
{
    setIO("fencedin");
    int a, b, n, m; cin >> a >> b >> n >> m;
    //edge is pair(weight, pair(start, end)), so pair<int, pair<pii, pii>>
    vector<pair<int, pair<pii, pii>>> edges;
    ll length = 0;
    vi xx, yy;
    xx.pb(0); yy.pb(0);
    vi xvals, yvals;
    rep(i, 0, n) 
    {
        int x; cin >> x; xx.pb(x);
    }
    rep(j, 0, m)
    {
        int x; cin >> x; yy.pb(x);
    }
    xx.pb(a); yy.pb(b);
    sort(all(xx)); sort(all(yy));
    rep(i, 0, n + 1) 
    {
       yvals.pb(xx[i + 1] - xx[i]);
    }
    rep(i, 0, m + 1)
    {
       xvals.pb(yy[i + 1] - yy[i]);
    }
    rep(i, 0, m + 1) // n = 5, m = 2
    {
        rep(j, 0, n)
        {
            pii start, end; int dist;
            start = {i, j}; end = {i, j + 1};
            dist = xvals[i];
            edges.emplace_back(mp(dist, mp(start, end)));
        }
    }
    rep(i, 0, m)
    {
        rep(j, 0, n + 1)
        {
            pii start, end; int dist;
            start = {i, j}; end = {i + 1, j};
            dist = yvals[j];
            edges.emplace_back(mp(dist, mp(start, end)));
        }
    }
    dsu d; d.init(2010, 2010);
  	sort(all(edges));
  	// cerr << edges.size() << endl;
    for(int i = 0; i < edges.size(); i++)
    {
        int weight = edges[i].first; pii start = edges[i].second.first, end = edges[i].second.second;
      	// cerr << start.first << " " << start.second << " " << end.first << " " << end.second << " " << weight << endl;
        if(d.find(start) != d.find(end))
        {
            length += weight;
            d.merge(start, end);
        }
    }
    cout << length << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
