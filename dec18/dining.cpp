#include <bits/stdc++.h>

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
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.first << ", " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cerr << i << " "; cerr << endl;}

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

void solve()
{
    setIO("dining");
    int n, m, k; cin >> n >> m >> k;
    vector<vii> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb(mp(w, v));
        adj[v].pb(mp(w, u));
    }   
    vii bales(k);
    for(int i = 0; i < k; i++) cin >> bales[i].first >> bales[i].second;

    vi distn(n + 1, 1e9); distn[n] = 0;
    vb v(n + 1);
    priority_queue<pii, vii, greater<pii>> pq;
    pq.push(mp(0, n));
    while(!pq.empty())
    {
        pii curr = pq.top(); pq.pop();
        if(v[curr.second]) continue;
        v[curr.second] = 1;
        for(auto adjnode : adj[curr.second])
        {
            if(v[adjnode.second]) continue;
            if(distn[curr.second] + adjnode.first < distn[adjnode.second])
            {
                distn[adjnode.second] = distn[curr.second] + adjnode.first;
                pq.push(mp(distn[adjnode.second], adjnode.second));
            }
        }
    }
    vi dist0(n + 1, 1e9);
    for(int i = 0; i < k; i++) 
    {
        pii bale = bales[i];
        dist0[bale.first] = distn[bale.first] - bale.second;
        pq.push(mp(dist0[bale.first], bale.first));
    }
    v.clear(); v.resize(n + 1);
    while(!pq.empty())
    {
        pii curr = pq.top(); pq.pop();
        if(v[curr.second]) continue;
        v[curr.second] = 1;
        for(auto adjnode : adj[curr.second])
        {
            if(v[adjnode.second]) continue;
            if(dist0[curr.second] + adjnode.first < dist0[adjnode.second])
            {
                dist0[adjnode.second] = dist0[curr.second] + adjnode.first;
                pq.push(mp(distn[adjnode.second], adjnode.second));
            }
        }
    }
    for(int i = 1; i < n; i++)
    {
        cout << (distn[i] >= dist0[i]) << endl;
    }
    // DBGvec(distn); DBGvec(dist0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
