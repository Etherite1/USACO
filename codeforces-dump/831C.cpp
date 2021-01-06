#include <bits/stdc++.h>

using namespace std;

#define ll long long
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
#define f first
#define s second

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

int n, k; 
vi a, b, pref;

bool chk(int x)
{
    unordered_set<int> s;
    rep(i, 0, n) s.insert(x + pref[i]);
    for(int x : b) if(!s.count(x)) return 0;
    return 1;
}

void solve()
{
    cin >> n >> k;
    a.resize(n); rep(i, 0, n) cin >> a[i];
    b.resize(k); rep(i, 0, k) cin >> b[i];
    pref.resize(n + 1);
    rep(i, 0, n) pref[i + 1] = pref[i] + a[i];
    pref.erase(pref.begin());
    unordered_set<int> todo;
    rep(i, 0, n) todo.insert(b[0] - pref[i]);
    int ans = 0;
    for(int x : todo) ans += chk(x);
    cout << ans << endl;
}

int main()
{
    fastio

    if(fopen("file.in", "r"))
    {
        freopen("file.in","r",stdin);
        freopen("file.out","w",stdout);
    }

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
