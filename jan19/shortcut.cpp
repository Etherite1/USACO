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
const ll INF = 1e17;

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

vl cnt, par;

void solve()
{
    setIO("shortcut");
    ll n, m, t; cin >> n >> m >> t;
    vl a(n); rep(i, 0, n) cin >> a[i];
    vector<vector<pll>> adj(n);
    rep(i, 0, m)
    {
        int u, v, w; cin >> u >> v >> w;
        adj[u - 1].pb({w, v - 1});
        adj[v - 1].pb({w, u - 1});
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq; pq.push({0, 0});
    vb v(n);
    vl d(n, INF); par.resize(n); cnt.resize(n); fill(all(par), -1);
    d[0] = 0;
    while(!pq.empty())
    {
        pll curr = pq.top(); pq.pop();
        if(v[curr.second]) continue;
        v[curr.second] = 1;
        for(pll adjnode : adj[curr.second])
        {
            if(v[adjnode.second]) continue;
            if(d[adjnode.second] > d[curr.second] + adjnode.first)
            {
                d[adjnode.second] = d[curr.second] + adjnode.first;
                pq.push({d[adjnode.second], adjnode.second});
                par[adjnode.second] = curr.second;
            }
            else if(d[adjnode.second] == d[curr.second] + adjnode.first)
            {
                if(curr.second < par[adjnode.second])
                {
                    par[adjnode.second] = curr.second;
                    pq.push({d[adjnode.second], adjnode.second});
                }
            }
        }
    }
    rep(i, 0, n)
    {
        int j = i;
        while(j != -1)
        {
            cnt[j] += a[i];
            j = par[j];
        }
    }

    ll ans = 0;
    rep(i, 0, n)
    {
        ans = max(ans, cnt[i] * (d[i] - t));
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
