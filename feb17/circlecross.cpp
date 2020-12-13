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

struct bit 
{
    vl tree;
    bit(int n) {tree = vl(n + 5, 0);}

    ll rsq(int idx) 
    {
        ll sum = 0; 
        while(idx > 0)
        {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum; 
    }

    ll rsq(int a, int b) // 0 based indexing range query
    {
        a++; b++;
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); 
    }

    void upd(int idx, int val) // 0 based indexing point update
    {
        idx++;
        while(idx < tree.size() - 1)
        {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
};

void solve()
{
    setIO("circlecross");
    int n; cin >> n; vi a(2 * n); rep(i, 0, 2 * n) cin >> a[i];
    rep(i, 0, 2 * n) a[i]--;
    bit tree(2 * n);
    map<int, pii> m;
    rep(i, 0, 2 * n)
    {
        if(m.find(a[i]) != m.end()) m[a[i]].second = i;
        else m[a[i]].first = i;
    }
    vb v(n);
    vi ans(n);
    rep(i, 0, 2 * n)
    {   
        if(v[a[i]])
        {
            tree.upd(m[a[i]].first, -2);
            tree.upd(m[a[i]].second, 1);
            ans[a[i]] = tree.rsq(m[a[i]].first, m[a[i]].second);
        }
        else
        {
            v[a[i]] = 1;
            tree.upd(m[a[i]].first, 1);
        }
    }
    int sum = 0;
    for(int i : ans) sum += i;
    cout << sum / 2 << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
