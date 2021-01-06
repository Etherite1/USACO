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
    int n, m; cin >> n >> m;
    vvi grid(n, vi(m));
    vvi diags;
    vi cnt(n / 2 + 1);   
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> grid[i][j];
        }
    }
    //width is m, height is n
    for(int i = 0; i <= n + m - 2; i++)
    {
        vi curr;
        for(int j = 0; j <= i; j++)
        {
            int k = i - j;
            if(k < n && j < m) curr.pb(grid[k][j]);
        }
        diags.pb(curr);
    }

    int sz = diags.size();
    int ans = 0;
    rep(i, 0, sz / 2)
    {
        int cnt1 = 0, cnt0 = 0;
        vi f = diags[i], s = diags[n + m - i - 2];
        for(int i : f) 
        {
            if(i == 1) cnt1++;
            else cnt0++;
        }
        for(int i : s)
        {
            if(i == 1) cnt1++;
            else cnt0++;
        }
        if(cnt1 > cnt0) ans += cnt0;
        else ans += cnt1;
    }
    cout << ans << endl;
}

int main()
{
    fastio

    int t = 1;
    cin >> t;

    while(t-- > 0) solve();
}
