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
template <class T> void DBGvec(vector<T> a){}
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

#define ff first
#define ss second

void solve()
{
    setIO("pump");
    int n, m; cin >> n >> m;
    vector<vector<pipii>> adj(n);
    for(int i = 0; i < m; i++)
    {
        ll u, v, a, b; cin >> u >> v >> a >> b;
        u--; v--;
        adj[u].pb(mp(v, mp(a, b)));
        adj[v].pb(mp(u, mp(a, b)));
    }

    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
    vvl dist(n, vl(1050, INF));
    vvb v(n, vb(1050));
    pq.push(mp(0, mp(0, 1000)));
    dist[0][1000] = 0;
    while(!pq.empty())
    {
        pipii curr = pq.top(); pq.pop();
        DBGpair(curr.ss);
        v[curr.ss.ff][curr.ss.ss] = 1;
        for(auto adjnode : adj[curr.ss.ff])
        {
            int flow = min(adjnode.ss.ss, curr.ss.ss);
            int cost = dist[curr.ss.ff][curr.ss.ss] + adjnode.ss.ff;
            if(v[adjnode.ff][flow]) continue;
            if(dist[adjnode.ff][flow] > cost)
            {
                dist[adjnode.ff][flow] = cost;
                pq.push(mp(dist[adjnode.ff][flow], mp(adjnode.ff, flow)));
            }
        }
    }
    ll ans = 0;
    for(int j = 1; j <= 1000; j++)
    {
        ll x = j, y = dist[n - 1][j];
        x *= 1000000ll;
        ans = max(ans, x / y);
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
