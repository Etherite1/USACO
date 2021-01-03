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

ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}

template <class T> void printvec(vector<T> a)
{
    for(T i : a) cout << i << " ";
    cout << endl;
}

ll aceil(ll num, ll denom)
{
    return (num + denom - 1) / denom;
}

bool cmp(pii a, pii b)
{
    return a.second < b.second;
}

void solve()
{
    int n; cin >> n;
    vii a(n); for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(all(a));
    for(int i = 0; i < n; i++) a[i].first = i + 1;
    sort(all(a), cmp);
    for(int i = 0; i < n; i++) a[i].second = i + 1;
    vvi pref(n + 1, vi(n + 1));
    for(int i = 0; i < n; i++) pref[a[i].first][a[i].second] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int xl = min(a[i].first, a[j].first), xr = max(a[i].first, a[j].first);
            int yb = min(a[i].second, a[j].second), yt = max(a[i].second, a[j].second); 
            ll below = pref[xl][yt] - pref[xl][yb - 1] - pref[0][yt] + pref[0][yb - 1];
            ll above = pref[n][yt] - pref[n][yb - 1] - pref[xr - 1][yt] + pref[xr - 1][yb - 1];
            ans += below * above;
        }
    }
    cout << ans + 1 << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
