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
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()
#define watch(x) cout << (#x) << " is " << (x) << endl

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;

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

bool cmp()
{
    return 0;
}

void solve()
{
    int n, x; cin >> n >> x;
    vector<vector<pll>> a(200200), b(200200);
    vl mini(200200, INF);

    for(int i = 0; i < n; i++)
    {
        int l, r, w; cin >> l >> r >> w;
        a[l].pb(mp(r - l + 1, w));
        b[r].pb(mp(r - l + 1, w));
    }
    ll ans = INF;
    for(int i = 0; i < 200200; i++)
    {
        for(auto j : a[i])
        {
            int val = x - j.first;
            if(val >= 0 && mini[val] != INF)
            {
                ans = min(ans, j.second + mini[val]);
            }
        }
        for(pll j : b[i]) mini[j.first] = min(mini[j.first], j.second);
    }
    cout << (ans == INF? -1 : ans) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
