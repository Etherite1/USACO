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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

bool cmp()
{
    return 0;
}

void solve()
{
    int n; cin >> n;
    vl o(n); rep(i, 0, n) cin >> o[i];
    vl t(n); rep(i, 0, n) cin >> t[i];
    set<int> used;
    vector<pll> v(n); rep(i, 0, n) v[i] = mp(o[i], t[i]);
    rep(i, 0, n) used.insert(o[i]);

    sort(all(v));
    priority_queue<int> q;
    int i = 0, a = 0;
    ll cs = 0, s = 0;
    for(int a = 0; 1; a++)
    {
        if(q.size() == 0)
        {
            if(i == v.size()) break;
            a = v[i].first;
        }
        while(i < v.size() && a == v[i].first)
        {
            q.push(v[i].second);
            cs += v[i].second;
            i++;
        }
        cs -= q.top(); q.pop();
        s += cs;
    }
    cout << s << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
