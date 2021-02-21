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

//each right cow contributes l - xi to the multiset, and each left cow contributes xi
//let's say we have a left cows
// we assign the xi of the -1 cows to the leftmost a cows, and the l - xi of the 1 cows to the rightmost n - a cows


void solve()
{
    setIO("meetings");
    ll n, l; cin >> n >> l;
    vl left, right; vll cows, dir;
    for(int i = 0; i < n; i++)
    {
        ll a, b, c; cin >> a >> b >> c;
        if(c == -1) left.pb(b);
        else right.pb(b);
        cows.pb(mp(b, a));
        dir.pb(mp(b, c));
    }
    sort(all(cows));
    sort(all(left)); sort(all(right));
    vll v;
    for(int i = 0; i < left.size(); i++) v.pb(mp(left[i], cows[i].second));
    for(int i = 0; i < right.size(); i++) v.pb(mp(l - right[i], cows[left.size() + i].second));
    sort(all(v));
    ll sumw = 0; for(auto i : cows) sumw += i.second;
    ll currw = 0, t = 0;
    for(int i = 0; i < n; i++)
    {
        currw += v[i].second;
        if(currw * 2 >= sumw)
        {
            t = v[i].first; break;
        }
    }
    ll meets = 0;
    queue<ll> q;
    sort(all(dir));
    for(int i = 0; i < n; i++)
    {
        if(dir[i].second == -1)
        {
            while(!q.empty() && q.front() + 2 * t < dir[i].first) q.pop();
            meets += q.size();
        }
        else q.push(dir[i].first);
    }
    cout << meets << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
