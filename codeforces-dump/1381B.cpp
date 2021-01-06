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
    for(T i : a) cerr << i << " ";
    cerr << endl;
}

bool cmp()
{
    return 0;
}

void solve()
{
    int n; cin >> n;
    vi a(2 * n); rep(i, 0, 2 * n) cin >> a[i];   
    int segcount = 0, wanted = 2 * n;
    vi segs;
    brep(i, n - 1, -1)
    {
        if(a[i] == wanted)
        {
            segcount++;
            segs.pb(segcount);
            wanted--;
            segcount = 0;
        }
        else
        {
            segcount++;
        }
    }

    int k = segs.size();
    vvb dp(k + 1, vb(n + 1));
    rep(i, 0, k + 1) dp[i][0] = 1;
    rep(i, 1, n + 1) dp[0][i] = 0;
    rep(i, 1, k + 1)
    {
        rep(j, 1, n + 1)
        {
            if(j < a[i - 1]) dp[i][j] = dp[i - 1][j];
            if(j >= a[i - 1]) dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
        }
    }
    cout << (dp[k][n]? "YES" : "NO") << endl;
}

int main()
{
    fastio

    int t = 1;
    cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
