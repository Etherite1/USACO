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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

bool find(ll d, vector<pll> segs, int n)
{
    ll last = -1 * d;
    ll cowcnt = 0;
    rep(i, 0, segs.size())
    {
        pll currseg = segs[i];
        ll start = max(currseg.first, last + d);
        while(start <= currseg.second)
        {
            cowcnt++;
            start += d;
            if(cowcnt >= n) return 1;
        }
        last = start - d;
    }
    // cerr << d << " " << cowcnt << endl;
    return cowcnt >= n;
}

void solve()
{
    setIO("socdist");
    int n, m; cin >> n >> m;
    vector<pll> grass(m);   
    rep(i, 0, m)
    {
        cin >> grass[i].first >> grass[i].second;
    }
    sort(all(grass));

    ll l = 1, r = 1e18;
    while(r - l > 1)
    {
        ll mid = (l + r) / 2;
        if(find(mid, grass, n)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
