#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()

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
    for(T i : a) cout << i << " ";
    cout << endl;
}

bool cmp()
{
    return 0;
}

int n, h, l, r;

bool good(int x)
{
    if(x <= r && x >= l) return 1;
    else return 0;
}

void solve()
{
    cin >> n >> h >> l >> r;
    vi a(n); rep(i, 0, n) cin >> a[i];
    vvi dp(n + 1, vi(h + 1));   
    vector<vb> pos(n + 1, vb(h + 1));
    pos[0][0] = 1;
    int ans = 0;
    rep(i, 0, n)
    {
        rep(j, 0, h + 1)
        {
            if(!pos[i][j]) continue;
            pos[i + 1][(j + a[i]) % h] = pos[i + 1][(j + a[i] - 1) % h] = 1;
            dp[i + 1][(j + a[i]) % h] = max(dp[i + 1][(j + a[i]) % h], dp[i][j] + good((j + a[i]) % h));
            dp[i + 1][(j + a[i] - 1) % h] = max(dp[i + 1][(j + a[i] - 1) % h], dp[i][j] + good((j + a[i] - 1) % h));
        }
    }
    rep(i, 0, h + 1) ans = max(ans, dp[n][i]);
    cout << ans << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
