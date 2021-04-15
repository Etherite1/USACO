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

struct dsu
{
    vector<int> parent, sz;
    void init(int n)
    {
        parent = vector<int>(n + 10), sz = vector<int>(n + 10, 1);
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
    
    bool same_set(int a, int b)
    {
        return find(a) == find(b);
    }
};


void solve()
{
    int n; cin >> n;
    map<int, vi> portals;
    vector<pipii> edges;

    dsu d; d.init(2 * n);

    for(int i = 0; i < n; i++)
    {
        int cost, a, b, c, d; cin >> cost >> a >> b >> c >> d;
        int idx1 = 2 * i, idx2 = 2 * i + 1;
        portals[a].pb(idx1); portals[b].pb(idx1);
        portals[c].pb(idx2); portals[d].pb(idx2);
        edges.pb(mp(cost, mp(idx1, idx2)));
    }
    sort(all(edges));
    for(auto i : portals) d.merge(i.second[0], i.second[1]);
    int ans = 0;
    for(auto i : edges)
    {
        if(d.same_set(i.second.first, i.second.second)) continue;
        else
        {
            ans += i.first;
            d.merge(i.second.first, i.second.second);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
