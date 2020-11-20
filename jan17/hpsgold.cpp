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
#define f first
#define s second

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

bool win(int bess, int fj)
{
    if(bess == 0 && fj == 2) return true;
    if(bess == 1 && fj == 0) return true;
    if(bess == 2 && fj == 1) return true;
    else return false;
}

void solve()
{
    setIO("hps");   
    int n, switches; cin >> n >> switches;
    vi a(n);
    rep(i, 0, n)
    {
        char x; cin >> x;
        if(x == 'H') a[i] = 0;
        else if(x == 'P') a[i] = 1;
        else a[i] = 2;
    }
    vector<vvi> dp(n + 1, vvi(switches + 1, vi(3)));
    rep(i, 0, n + 1)
    {
        rep(j, 0, switches + 1)
        {
            rep(k, 0, 3)
            {
                if(i == 0)
                {
                    dp[i][j][k] = 0;
                    continue;
                }
                // don't switch
                if(j == 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + win(k, a[i - 1]));
                // switch
                int s1 = (k + 1) % 3, s2 = (k + 2) % 3;
                if(j > 0) dp[i][j][k] = max({dp[i - 1][j][k], dp[i - 1][j - 1][s1], dp[i - 1][j - 1][s2]}) + win(k, a[i - 1]);
            }
        }
    }
    cout << max({dp[n][switches][0], dp[n][switches][1], dp[n][switches][2]});
    
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
