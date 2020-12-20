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
    setIO("sleepy");
    int n; cin >> n; vi a(n); rep(i, 0, n) cin >> a[i];
    bit tree(n);
    int nmk = 1; tree.upd(a[n - 1], 1);
    brep(i, n - 2, -1)
    {
        if(a[i] < a[i + 1])
        {
            nmk++;
            tree.upd(a[i], 1);
        }
        else break;
    }
    int k = n - nmk;
    cout << k << endl;
    int numleft = k - 1;
    rep(i, 0, k)
    {
        int q = tree.rsq(a[i]);
        if(i != k - 1) cout << q + numleft << " ";
        else cout << q + numleft;
        numleft--;
        tree.upd(a[i], 1);
    }
    cout << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
