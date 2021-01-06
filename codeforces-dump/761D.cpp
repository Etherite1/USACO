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
ll n, l, r;

bool in(ll x)
{
    return (x >= l && x <= r);
}

void solve()
{
    cin >> n >> l >> r;
    vl a(n), b(n);
    vector<pll> c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> c[i].first, c[i].second = i;
    sort(rall(c));
    ll currc = 0;
    b[c[0].second] = r;
    currc = r - a[c[0].second];
    // watch(currc);
    // c[i].first is the compressed value at i, c[i].second is the index
    for(int i = 1; i < n; i++)
    {
        // difference between b[i] and a[i] must be less than currc
        ll currb = min(currc + a[c[i].second] - 1, r);
        // watch(currb);
        if(!in(currb))
        {
            cout << "-1\n"; return;
        }
        else
        {
            b[c[i].second] = currb;
            currc = b[c[i].second] - a[c[i].second];
        }
    }
    printvec(b);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
