#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define plpll pair<long long, pair<long long, long long>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vii vector<pii>
#define vll vector<pll>
#define vl vector<long long>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()
#define rsz resize
#define sz(a) ((int)(a).size())

#ifdef Etherite_Local
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.first << ", " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cerr << i << " "; cerr << endl;}
mt19937 rnd(228);
#else
#define DBG1(x)
#define DBG2(x, y)
#define DBG3(x, y, z)
#define DBG4(a, b, c, d)
template<class T> void DBGpair(T a, string s = "") {return;}
template <class T> void DBGvec(vector<T> &a){}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
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

#define ff first
#define ss second

vll a;
int n;
ll overcount = 0, ans = 0;

void getans()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[j].ff - a[i].ff < abs(a[j].ss - a[i].ss)) continue;
            vl curr;
            ll xl = a[i].ff, xr = a[j].ff;
            ll len = xr - xl + 1, top = max(a[i].ss, a[j].ss) + 1, bot = top - len;
            ll top2 = min(a[i].ss, a[j].ss) + len;
            for(int k = 0; k < n; k++) if(a[k].ff >= xl && a[k].ff <= xr && a[k].ss >= bot && a[k].ss < top2) curr.pb(a[k].ss);
            sort(all(curr));
            // bot < coord of idxb, top < coord of idxt
            // idxb and idxt are the next points we will shift to
            ll idxb = 0, idxt = sz(curr);
            for(int k = 0; k < sz(curr); k++) if(curr[k] >= top) {idxt = k; break;}
            set<int> coords; for(auto k : curr) coords.insert(k);
            while(1)
            {
                if(bot > min(a[i].ss, a[j].ss)) break;
                ans++;
                if(coords.find(bot) != coords.end() && coords.find(top - 1) != coords.end()) overcount++;
                ll diff1 = curr[idxb] - bot + 1, diff2 = (idxt == sz(curr)? 1e9 : curr[idxt] - top + 1);
                ll add = min(diff1, diff2); top += add; bot += add;
                if(bot - 1 == curr[idxb]) idxb++;
                if(idxt < sz(curr) && top - 1 == curr[idxt]) idxt++;
            }
            // ans += sz(curr) - idxt;
            DBG2(ans, overcount);
        }
    }
}

void solve()
{
    cin >> n;
    ans = n + 1;
    a.rsz(n); for(auto &i : a) cin >> i.ff >> i.ss;
    sort(all(a));
    getans();
    for(auto &i : a) swap(i.ff, i.ss);
    sort(all(a));
    getans();
    DBG2(ans, overcount);
    cout << ans - overcount / 2 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
