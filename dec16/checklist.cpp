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
const ll INF = 1e17;

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

ll dist(pii x, pii y)
{
    ll x1 = x.first, x2 = x.second, y1 = y.first, y2 = y.second;
    return (x1 - y1) * (x1 - y1) + (x2 - y2) * (x2 - y2);
}

void solve()
{
    setIO("checklist");
    int h, g; cin >> h >> g;
    vii a(h + 1), b(g + 1);
    rep(i, 1, h + 1) cin >> a[i].first >> a[i].second;
    rep(i, 1, g + 1) cin >> b[i].first >> b[i].second;

    vector<vl> dp1(h + 10, vl(g + 10, INF)), dp2(h + 10, vl(g + 10, INF));
    dp1[1][0] = 0;
    rep(i, 1, h + 1)
    {
        rep(j, 0, g + 1)
        {
            if(i == 1 && j == 0) continue;
            if(i != 1) dp1[i][j] = min(dp1[i][j], dp1[i - 1][j] + dist(a[i - 1], a[i]));
            dp1[i][j] = min(dp1[i][j], dp2[i - 1][j] + dist(a[i], b[j]));
            if(j != 0)
            {
                dp2[i][j] = min(dp2[i][j], dp1[i][j - 1] + dist(a[i], b[j]));
                dp2[i][j] = min(dp2[i][j], dp2[i][j - 1] + dist(b[j], b[j - 1]));
            }
        }
    }
    cout << dp1[h][g];
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
