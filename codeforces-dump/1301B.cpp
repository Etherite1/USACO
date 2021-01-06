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
    for(T i : a) cerr << i << " ";
    cerr << endl;
}

bool cmp()
{
    return 0;
}

ll find(vl a, int k)
{
    rep(i, 0, a.size()) if(a[i] == -1) a[i] = k;
    ll maxdist = 0;
    rep(i, 0, a.size() - 1) maxdist = max(maxdist, abs(a[i] - a[i + 1]));
    return maxdist;
}

void solve()
{
    int n; cin >> n; vl a(n); rep(i, 0, n) cin >> a[i];

    int l = -1, r = 1e9;
    while(r - l > 1)
    {
        int mid = (r + l) / 2;
        ll curr = find(a, mid);
        ll o = find(a, mid + 1);
        if(curr <= o)
        {
            r = mid;
        }
        else l = mid;
    }
    rep(i, 0, n) if(a[i] == -1) a[i] = r;
    ll ans = 0;
    rep(i, 0, n - 1) ans = max(ans, abs(a[i] - a[i + 1]));
    cout << ans << " " << r << endl;
}

int main()
{
    fastio

    int t = 1;
    cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
