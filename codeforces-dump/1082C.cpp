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
    for(T i : a) cout << i << " ";
    cout << endl;
}

bool cmp()
{
    return 0;
}

void solve()
{
    int n, m; cin >> n >> m;
    vii a(n);
    rep(i, 0, n) cin >> a[i].first >> a[i].second;
    rep(i, 0, n) a[i].first--;
    sort(all(a));
    vvi sub(m);
    rep(i, 0, n) sub[a[i].first].pb(a[i].second); 
    rep(i, 0, m) sort(all(sub[i]));
    rep(i, 0, m) reverse(all(sub[i]));
    vector<vl> psums(m);
    rep(i, 0, m) psums[i].pb(0);
    rep(i, 0, m)
    {
        rep(j, 0, sub[i].size())
        {
            // cout << i << " " << j << endl << flush;
            psums[i].pb(psums[i][j] + sub[i][j]);
        }
    }
    vl sizes(n + 1);
    rep(i, 0, m)
    {
        rep(j, 0, psums[i].size()) sizes[j] += max(psums[i][j], 0ll);
    }
    ll ans = 0;
    for(ll i : sizes) ans = max(ans, i);
    cout << ans << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
