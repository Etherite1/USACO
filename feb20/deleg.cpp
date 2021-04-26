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
#define sz(a) ((int)(a).size())

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

vvi adj;
bool flag = 1;
vi cnt(100010);

int dfs(int curr, int par, int k)
{
    // cout << curr << endl;
    if(!flag) return -1;
    vi toadd;
    for(auto adjnode : adj[curr])
    {
        if(adjnode == par) continue;
        int x = dfs(adjnode, curr, k);
        if(!flag) return -1;
        toadd.pb(x + 1);
    }
    for(auto i : toadd) cnt[i]++;
    for(auto i : toadd)
    {
        if(cnt[i] == 0 || cnt[k - i] == 0) continue;
        if(i == k - i)
        {
            cnt[i] %= 2;
            continue;
        }
        int x = min(cnt[i], cnt[k - i]);
        cnt[i] -= x;
        cnt[k - i] -= x;   
    }
    cnt[k] = 0;
    int tot = 0, val = 0;
    for(auto i : toadd)
    {
        if(cnt[i] > 0) val = i, tot += cnt[i], cnt[i] = 0;
    }
    // DBG3(curr, tot, val);
    // for(int i = 0; i <= 10; i++) cout << cnt[i] << " ";
    // cout << endl << endl;
    if(tot > 1) {flag = 0; return -1;}
    else 
    {
        cnt[val] = 0;
        return val;
    }
}

void solve()
{
    setIO("deleg");
    int n; cin >> n;
    adj.rsz(n); 
    for(int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // dfs(0, -1, 1);
    // cout << flag << endl;
    for(int i = 1; i < n; i++)
    {
        if((n - 1) % i == 0)
        {
            fill(all(cnt), 0);
            flag = 1;
            dfs(0, -1, i);
            cout << flag;
        }
        else cout << 0;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
