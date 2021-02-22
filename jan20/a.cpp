#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vii vector<pii>
#define vll vector<pll>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vl vector<long long>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()
#define rsz resize
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.first << ", " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cerr << i << " "; cerr << endl;}

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

ll n, k, m;

ll aceil(ll a, ll b)
{
    return (a + b - 1) / b;
}

bool f(ll x)
{
    ll rem = n;
    ll days = 0;
    while(rem > 0)
    {
        if((rem / x) <= m)
        { 
            // DBG2(rem, days);
            days += rem / m;
            rem %= m;
            if(rem > 0) days++;
            // DBG1(days);
            return days <= k;
        }
        ll give = rem / x;
        ll smmult = give * x;
        ll diff = rem - smmult;
        // DBG3(rem, days, give);
        rem -= (diff / give) * give;
        days += diff / give;
        if(rem >= smmult) days++, rem -= give;
        // DBG4(rem, days, smmult, diff);
    }
    return 1;
}

void solve()
{
    setIO("loan");
    ll l = 0, r = 1e18;
    cin >> n >> k >> m;

    while(r - l > 1)
    {
        ll mid = (l + r) / 2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    // f(1);
    cout << l << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    // cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
