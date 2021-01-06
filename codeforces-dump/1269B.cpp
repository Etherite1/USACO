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

void solve()
{
    ll n, m; cin >> n >> m;
    vl a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    map<ll, ll> bmap; map<ll, ll> nmap;
    rep(i, 0, n) bmap[b[i]]++;
    ll ans = 1e10;
    rep(i, 0, n)
    {
        ll diff = (b[i] - a[0]);
        if(diff < 0) diff += m;
        rep(j, 0, n)
        {
            nmap[(a[j] + diff) % m]++;
        }
        if(nmap.size() != bmap.size()) continue;
        else
        {
            bool flag = 1;
            for(auto i : nmap)
            {
                if(bmap.find(i.first) == bmap.end()) {flag = 0; break;}
                if(i.second != bmap[i.first]) {flag = 0; break;}
            }
            if(flag)
            {
                ans = min(ans, diff);
            }
        }
        nmap.clear();
    }   
    cout << ans << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
