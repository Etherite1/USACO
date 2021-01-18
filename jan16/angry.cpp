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

int n;
vl a;

bool chkr(ll pos, ll rad)
{
    ll tpos = pos, trad = rad;
    int idx = 0;
    bool row = 0;
    while(true)
    {
        if(idx >= n - 1) return true;
        if(trad == 0) return false;
        if(tpos + trad >= a[idx + 1]) idx++, row = 0;
        else
        {
            if(row) return false;
            trad -= 2;
            tpos = a[idx];
            row = 1;
        }
    }
}

bool chkl(ll pos, ll rad)
{
    ll tpos = pos, trad = rad;
    int idx = n - 1;
    bool row = 0;
    while(true)
    {
        if(idx <= 0) return true;
        if(trad == 0) return false;
        if(tpos - trad <= a[idx - 1]) idx--, row = 0;
        else
        {
            if(row) return false;
            trad -= 2;
            tpos = a[idx];
            row = 1;
        }
    }
}

bool find(ll rad)
{
    ll leftel = 0, rightel = 0;
    ll l = 0, r = a.back() + 2;
    while(r - l > 1)
    {
        ll mid = (l + r) / 2;
        if(chkr(mid, rad)) r = mid;
        else l = mid;
    }
    rightel = r;
    l = 0, r = a.back() + 2;
    while(r - l > 1)
    {
        ll mid = (l + r) / 2;
        if(chkl(mid, rad)) l = mid;
        else r = mid;
    }
    leftel = l;
    return leftel >= rightel;
}

void solve()
{
    setIO("angry");
    cin >> n;
    a.resize(n); for(auto &i : a) cin >> i;
    for(auto &i : a) i *= 2;   
    sort(all(a));
    ll l = 0, r = 2e9 + 100;
    while(r - l > 1)
    {
        ll mid = (l + r) / 2;
        if(find(mid)) r = mid;
        else l = mid;
    }
    // watch(find(205032675));
    cout << fixed << setprecision(1) << r / 2.0 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
