#include "bits/stdc++.h"

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

#ifdef Etherite_Local
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.first << ", " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cerr << i << " "; cerr << endl;}
#else
#define DBG1(x)
#define DBG2(x, y)
#define DBG3(x, y, z)
#define DBG4(a, b, c, d)
template<class T> void DBGpair(T a, string s = "") {return;}
template <class T> void DBGvec(vector<T> &a){}
#endif

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

struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t a) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(a + FIXED_RANDOM);
	}
	template<class T> size_t operator()(T a) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		hash<T> x;
		return splitmix64(x(a) + FIXED_RANDOM);
	}
	template<class T, class H> size_t operator()(pair<T, H> a) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		hash<T> x;
		hash<H> y;
		return splitmix64(x(a.first) * 37 + y(a.ssecond) + FIXED_RANDOM);
	}
};
template <class T, class H> using umap = unordered_map<T, H, custom_hash>;
template <class T> using uset = unordered_set<T, custom_hash>;

const int mxAi = 2e6 + 1;
const int mxN = 5005;

ll dp[mxN][mxN];
// ll precomp[mxN][mxN];
int curr[mxAi];

void solve()
{
    memset(dp, 0, sizeof(dp));
    // memset(precomp, 0, sizeof(precomp));
    memset(curr, 0, sizeof(curr));
    setIO("threesum");
    int n, q; cin >> n >> q;
    vi a(n); for(auto &i : a) cin >> i;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int need = -1 * (a[i] + a[j]);
            if(need + 1000000 >= 0 && need + 1000000 <= 2e6) dp[i][j] = curr[need + 1000000];
            curr[a[j] + 1000000]++;
        }
        for(int j = i + 1; j < n; j++) curr[a[j] + 1000000]--;
    }

    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = i + 1; j < n; j++)
        {
            dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
    }
    
    // for(int len = 3; len <= n; len++)
    // {
    //     for(int i = 0; i <= n; i++)
    //     {
    //         if(i + len >= n + 3) break;
    //         dp[i][len] = dp[i][len - 1] + dp[i + 1][len - 1] - dp[i + 1][len - 2] + precomp[i][i + len - 1];
    //     }
    // }
    while(q--)
    {
        int l, r; cin >> l >> r;
        cout << dp[l - 1][r - 1] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    // cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
