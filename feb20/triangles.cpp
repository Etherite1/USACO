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
#define rsz resize
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

int cmx = 2e4 + 10;

void solve()
{
    setIO("triangles");
    int n; cin >> n;
    vii a(n); for(auto &i : a) cin >> i.first >> i.second;
    for(auto &i : a) i.first += 1e4, i.second += 1e4;
    vvi xs(cmx), ys(cmx);
    for(auto i : a)
    {
        xs[i.first].pb(i.second);
        ys[i.second].pb(i.first);
    }
    for(auto &i : xs) sort(all(i));
    for(auto &i : ys) sort(all(i));
    vvl dx(cmx), dy(cmx);
    for(int i = 0; i < cmx; i++)
    {
        if(xs[i].size())
        {
            ll curr = 0;
            for(int j = 1; j < xs[i].size(); j++) curr += abs(xs[i][j] - xs[i][0]);
            dx[i].pb(curr);
            for(int j = 1; j < xs[i].size(); j++)
            {
                curr -= (xs[i].size() - 2 * j) * abs(xs[i][j] - xs[i][j - 1]);
                dx[i].pb(curr);
            }
        }
        if(ys[i].size())
        {
            ll curr = 0;
            for(int j = 1; j < ys[i].size(); j++) curr += abs(ys[i][j] - ys[i][0]);
            dy[i].pb(curr);
            for(int j = 1; j < ys[i].size(); j++)
            {
                curr -= (ys[i].size() - 2 * j) * abs(ys[i][j] - ys[i][j - 1]);
                dy[i].pb(curr);
            }
        }
    }
    // for(int i = 0; i < 2; i++) DBGvec(dx[i]);
    // for(int i = 0; i <= 2; i++) DBGvec(dy[i]);

    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        int x = a[i].first, y = a[i].second;
        int posx = lower_bound(all(xs[x]), y) - xs[x].begin();
        int posy = lower_bound(all(ys[y]), x) - ys[y].begin();
        ans += dx[x][posx] * dy[y][posy];
        ans %= MOD;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
