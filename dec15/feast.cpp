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

bitset<5000001> dp;
bitset<5000001> dp2;

void solve()
{   
    setIO("feast");
    int t, a, b; cin >> t >> a >> b;
    dp[0] = 1;
    rep(i, 0, t + 1)
    {
        if(i - a >= 0) dp[i] = dp[i] || dp[i - a];
        if(i - b >= 0) dp[i] = dp[i] || dp[i - b];
        if(dp[i]) dp2[i / 2] = 1;
    }   
    rep(i, 0, t + 1)
    {
        if(i - a >= 0) dp2[i] = dp2[i] || dp2[i - a];
        if(i - b >= 0) dp2[i] = dp2[i] || dp2[i - b];
    }
    int ans = 0;
    for(int i = 5000000; i >= 0; i--) if(dp[i]) {ans = i; break;}
    for(int i = 5000000; i >= 0; i--) if(dp2[i]) {cout << max(ans, i); return;}
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
