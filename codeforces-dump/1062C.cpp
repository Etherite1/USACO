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


ll modpow(ll x, ll y)  
{  
    ll res = 1; 
    x %= MOD; 
    if (x == 0) return 0;
    while (y > 0)  
    {
        if (y & 1)  
            res = (res * x) % MOD;  

        y = y >> 1; // y = y/2  
        x = (x * x) % MOD;  
    }  
    return res;  
}

void solve()
{
    int n, q; cin >> n >> q;
    vi orig(n);
    rep(i, 0, n)
    {
        char x; cin >> x; orig[i] = x - '0';
    }
    vi psums(n + 1);
    rep(i, 1, n + 1)
    {
        psums[i] = psums[i - 1] + orig[i - 1]; 
    }
    
    rep(i, 0, q)
    {
        int l, r; cin >> l >> r; 
        ll zeroes = (r - l + 1) - (psums[r] - psums[l - 1]);
        ll x = modpow(2, r - l + 1);
        ll y = modpow(2, zeroes);
        ll ans = x - y;
        if(ans < 0) ans += MOD;
        cout << ans << endl;
    }
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
