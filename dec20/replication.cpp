#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define plpll pair<long long, pair<long long, long long>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vii vector<pii>
#define vll vector<pll>
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
mt19937 rnd(228);
#else
#define DBG1(x)
#define DBG2(x, y)
#define DBG3(x, y, z)
#define DBG4(a, b, c, d)
template<class T> void DBGpair(T a, string s = "") {return;}
template <class T> void DBGvec(vector<T> &a){}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
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

const int N = 1050;
ll rdist[N][N], grid[N][N], vis[N][N], vis2[N][N];
vector<pii> st[N / 2];

void solve()
{
    ll n, d; cin >> n >> d;
    memset(rdist, -1, sizeof(rdist));
    queue<pii> q;
    vii starts;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char x; cin >> x;
            if(x == '#') grid[i][j] = 0, q.push(mp(i, j)), rdist[i][j] = 0;
            else if(x == '.') grid[i][j] = 1;
            else grid[i][j] = 2, starts.pb(mp(i, j));
        }
    }
    while(!q.empty())
    {
        pii c = q.front(); q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = c.first + dx[i], ny = c.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(rdist[nx][ny] != -1) continue;
            rdist[nx][ny] = rdist[c.first][c.second] + 1;
            q.push(mp(nx, ny));
        }
    }
    queue<pipii> q2;
    vii centers;
    for(auto i : starts) q2.push(mp(0, i)), vis[i.first][i.second] = 1;
    while(!q2.empty())
    {
        pii c = q2.front().second; int t = q2.front().first; q2.pop();
        centers.pb(c);
        for(int i = 0; i < 4; i++)
        {
            int nx = c.first + dx[i], ny = c.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[nx][ny] || !grid[nx][ny]) continue;
            if((t < d * rdist[c.first][c.second]) && (t + 1 <= d * rdist[nx][ny]))
            {
                vis[nx][ny] = 1;
                q2.push(mp(t + 1, mp(nx, ny)));
            }
        }
    }
    ll ans = 0;
    memset(vis, 0, sizeof(vis));
    for(auto i : centers) st[rdist[i.first][i.second]].pb(i);
    for(int i = n / 2 + 1; i >= 0; i--)
    {
        for(auto j : st[i]) if(rdist[j.first][j.second] > vis[j.first][j.second]) 
        {
            q2.push(mp(rdist[j.first][j.second], j));
            vis[j.first][j.second] = rdist[j.first][j.second];
        }
        while(!q2.empty())
        {
            pii c = q2.front().second; int t = q2.front().first; q2.pop();
            vis2[c.first][c.second] = 1;
            if(t == 0) continue;
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = c.first + dx[dir], ny = c.second + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(!grid[nx][ny] || (t - 1) <= vis[nx][ny]) continue;
                vis[nx][ny] = t - 1;
                q2.push(mp(t - 1, mp(nx, ny)));
            }
        }
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans += vis2[i][j];
    cout << ans << endl;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
