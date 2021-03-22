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


vvi grid, cost;
int n, m, k;
string s;

void dijk(int c)
{
    priority_queue<pii, vii, greater<pii>> q;
    cost[c][c] = 0;
    vb v(m);
    q.push(mp(0, c));
    while(q.size())
    {
        pii curr = q.top(); q.pop();
        if(v[curr.second]) continue;
        v[curr.second] = 1;
        for(int i = 0; i < m; i++)
        {
            if(v[i]) continue;
            if(curr.first + grid[curr.second][i] < cost[c][i])
            {
                cost[c][i] = curr.first + grid[curr.second][i];
                q.push(mp(cost[c][i], i));
            }
        }
    }
}

void solve()
{
    setIO("cowmbat");
    cin >> n >> m >> k >> s;
    grid = vvi(m, vi(m));
    cost = vvi(m, vi(m, 1e5));
    for(int i = 0; i < m; i++) for(int j = 0; j < m; j++) cin >> grid[i][j];
    for(int i = 0; i < m; i++) dijk(i);
    for(auto i : cost) DBGvec(i);
    vvi dp(n + 1, vi(m, INF));
    vi mn(n + 1, INF);
    mn[0] = 0;
    vvi pref(m + 1, vi(n + 1));
    for(int c = 0; c < m; c++)
        for(int i = 1; i <= n; i++) 
            pref[c][i] = pref[c][i - 1] + cost[s[i - 1] - 'a'][c];

    for(int i = 1; i <= n; i++)
    {
        for(int c = 0; c < m; c++)
        {
            int chg = dp[i - 1][c] + pref[c][i] - pref[c][i - 1];
            if(i - k >= 0) chg = min(chg, mn[i - k] + pref[c][i] - pref[c][i - k]);
            dp[i][c] = min(dp[i][c], chg);
            mn[i] = min(dp[i][c], mn[i]);
        }
    }
    cout << mn[n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
