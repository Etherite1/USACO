#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vii vector<pii>
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
    setIO("cbarn2");
    /*
    dp[i][j][k] = minimum distance carrying first i cows and last door unlocked was j, having unlocked k doors
    base case: dp[0][0][0] = 0, dp[0][0][1] = 1

    not add door or add door

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int k = 0; k <= doors; k++)
            {
                // not add door
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + a[i] * (i - k);
                
                // add door
                dp[i + 1][i][k + 1] = min(dp[i + 1][i][k + 1], dp[i][j][k]);
            }
        }
    }
    */
    // int n, doors; cin >> n >> doors;
    // vi arr(n); for(auto &i : arr) cin >> i;
    // for(int i = 0; i < n; i++) arr.pb(arr[i]);
    // ll minans = 1e18;
    // for(int st = 0; st < n; st++)
    // {
    //     vi a = {0};
    //     for(int i = st; i < st + n; i++) a.pb(arr[i]);

    //     vector<vvl> dp(n + 5, vvl(n + 5, vl(doors + 2, 1e18)));
    //     // must add door at position 1
    //     dp[1][1][1] = 0;

    //     for(int i = 1; i < n; i++) // loop current position
    //     {
    //         for(int j = 1; j <= i; j++) // loop last position
    //         {
    //             for(int k = 1; k <= doors; k++)
    //             {
    //                 // not add door
    //                 dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + a[i + 1] * (i - j + 1));
                
    //                 // add door
    //                 dp[i + 1][i][k + 1] = min(dp[i + 1][i][k + 1], dp[i][j][k]);
    //             }
    //         }
    //     }
    //     for(int i = 1; i <= n; i++) minans = min(minans, dp[n][i][doors]);

    //     if(st == 1)
    //     {
    //         for(int i = 1; i <= n; i++)
    //         {
	// 			cout << i << endl;
    //             for(auto j : dp[i]) DBGvec(j);
    //         }
    //     }
    // }
    // cout << minans << endl;

    int n, doors; cin >> n >> doors;
    vi arr(n); for(auto &i : arr) cin >> i;
    vvl dp(n + 1, vl(doors + 1));
    ll ans = 1e18;
    for(int i = 0; i < n; i++)
    {
        dp = vector<vl>(n + 1, vl(doors + 1, 1e18));
        vl a;
        for(int j = 0; j < i; j++) a.pb(arr[(i + j) % n]);
        dp[n][0] = 0;
        for(int k = 1; k <= doors; k++)
        {
            for(int j = 0; j < n; j++)
            {
                ll val = 0;
                for(int l = j + 1; l <= n; l++)
                {
                    val += a[l - 1] * (l - j - 1);
                    dp[j][k] = min(dp[j][k], val + dp[l][k - 1]);
                }
            }
        }
        ans = min(ans, dp[0][doors]);
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
