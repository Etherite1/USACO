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
const int INF = 1e9;

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

void solve()
{
    setIO("248");
    int n; cin >> n;
    vi a(n); rep(i, 0, n) cin >> a[i];   
    vvi dp(n, vi(n));
    int ans = 0;
    //dp[i][j] stands for max subinterval from i with j + 1 length
    rep(l, 0, n) // iterate length of subarray
    {
        rep(i, 0, n - l) // iterate start of subarray
        {
            if(l == 0) {dp[i][l] = a[i]; continue;}
            rep(j, 0, l) // iterate end of subarray
            {
                if(dp[i][j] == dp[i + j + 1][l - j - 1] && dp[i][j] != 0)
                    dp[i][l] = max(dp[i][l], dp[i][j] + 1);
            }
            ans = max(ans, dp[i][l]);
        }
    }
    cout << ans << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
