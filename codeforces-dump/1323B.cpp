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

vl gao(vi a) 
{
    int n = a.size();
    vl res(n + 1);
    int i = 0;
    while (i < n) 
    {
        if (a[i] == 0) {i++; continue;}
        int j = i;
        while (j < n && a[j] == 1) j++;
        for (int len = 1; len <= j - i; len++) res[len] += j - i - len + 1;
        i = j;
    }
    return res;
}

void solve()
{
    ll n, m, k; cin >> n >> m >> k;
    vi a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(j, 0, m) cin >> b[j];

    ll ans = 0;
    vl ga = gao(a);
    vl gb = gao(b);
    rep(i, 1, ga.size())
    {
        if(k % i == 0 && k / i <= m) ans += ga[i] * gb[k / i];
    }
    cout << ans << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
