#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
#define rall(x) (x).rbegin(),(x).rend()
#define endl "\n"
#define rsz resize
#define sz(a) ((int)(a).size())

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update > oset; // find_by_order, order_of_key
#define fbo find_by_order
#define ook order_of_key
#define bitcount __builtin_popcount

#ifdef Etherite_Local
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
#define DBG5(a, b, c, d, e) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << " " << (#e) << ": " << a << " " << b << " " << c << " " << d << " " << e << endl;
#define DBG6(a, b, c, d, e, f) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << " " << (#e) << " " << (#f) << ": " << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.first << ", " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cerr << i << " "; cerr << endl;}
template <class T> void DBGset(set<T> a){for(T i : a) cerr << i << " "; cerr << endl;}
mt19937 rnd(228);
#else
#define DBG1(x)
#define DBG2(x, y)
#define DBG3(x, y, z)
#define DBG4(a, b, c, d)
#define DBG5(a, b, c, d, e)
#define DBG6(a, b, c, d, e, f)
template<class T> void DBGpair(T a, string s = "") {return;}
template <class T> void DBGvec(vector<T> &a){}
template <class T> void DBGset(set<T> &a){}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353

ll add(ll a, ll b) {return (a + b) % MOD;}
ll sub(ll a, ll b)
{
    ll x = a - b;
    while(x < 0) x += MOD;
    return x;
}
ll mul(ll a, ll b) {return (a * b) % MOD;}
// ll divi(ll a, ll b) {return (a * modinv(b, MOD)) % MOD;}

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

const int N = 210;
int dp[N][N], bestv[N][N], besth[N][N];

int rec(int x1, int y1, int x2, int y2)
{
    int ans = dp[x2][y2];
    if(x1) ans -= dp[x1 - 1][y2];
    if(y1) ans -= dp[x2][y1 - 1];
    if(x1 && y1) ans += dp[x1 - 1][y1 - 1];
    return ans;
}

void solve()
{
    setIO("paintbarn");
    int n, k; cin >> n >> k;   
    for(int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        dp[x1][y1]++;
        dp[x1][y2]--;
        dp[x2][y1]--;
        dp[x2][y2]++;
    }

    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j++)
        {
            if(i) dp[i][j] += dp[i - 1][j];
            if(j) dp[i][j] += dp[i][j - 1];
            if(i && j) dp[i][j] -= dp[i - 1][j - 1];
        }

    int ans = 0, toadd = 0;
    for(int i = 0; i < 200; i++)
    {
        for(int j = 0; j < 200; j++)
        {
            if(dp[i][j] == k) dp[i][j] = -1, ans++;
            else if(dp[i][j] == k - 1) dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }

    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j++)
        {
            if(i) dp[i][j] += dp[i - 1][j];
            if(j) dp[i][j] += dp[i][j - 1];
            if(i && j) dp[i][j] -= dp[i - 1][j - 1];
        }

    for(int l = 0; l < 200; l++)
        for(int r = l; r < 200; r++)
        {
            bestv[l][r] = -1e9, besth[l][r] = -1e9;
            int sumh = 0, sumv = 0;
            for(int i = 0; i < 200; i++)
            {
                sumh = max(sumh + rec(l, i, r, i), rec(l, i, r, i));
                sumv = max(sumv + rec(i, l, i, r), rec(i, l, i, r));
                bestv[l][r] = max(bestv[l][r], sumv);
                besth[l][r] = max(besth[l][r], sumh);
            }
        }
    
    for(int i = 0; i < 200; i++) // dividing line
    {
        int lh = 0, lv = 0, rh = 0, rv = 0;
        for(int l = 0; l < i; l++)
            for(int r = l; r < i; r++)
            {
                lh = max(lh, besth[l][r]);
                lv = max(lv, bestv[l][r]);
            }
        
        for(int l = i; l < 200; l++)
            for(int r = l; r < 200; r++)
            {
                rh = max(rh, besth[l][r]);
                rv = max(rv, bestv[l][r]);
            }
        
        toadd = max(toadd, max(lh + rh, lv + rv));
    }
    cout << ans + toadd << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
