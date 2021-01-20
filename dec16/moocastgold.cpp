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
#define DBG1(x) cout << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cout << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cout << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cout << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template<class T> void DBGpair(T a, string s = "") {cout << s << (s == ""? "" : ": ") <<  a.first << " " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cout << i << " "; cout << endl;}

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

int dist(pii a, pii b)
{
    int xdir = b.first - a.first, ydir = b.second - a.second;
    return xdir * xdir + ydir * ydir;
}

struct dsu
{
    vector<int> parent, sz;
    void init(int n)
    {
        parent = vector<int>(n + 10), sz = vector<int>(n + 10, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }  

    int find(int x)
    {
        if(parent[x] == x) return x;
        else return parent[x] = find(parent[x]);
    }

    void merge(int a, int b)
    {
        int roota = find(a), rootb = find(b);
        if(sz[roota] > sz[rootb]) swap(roota, rootb);
        parent[roota] = rootb; sz[rootb] += sz[roota];
    }
};

void solve()
{
    setIO("moocast");
    int n; cin >> n;
    vii a(n); for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;   
    vector<pipii> edges;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            edges.pb(mp(dist(a[i], a[j]), mp(i, j)));
        }
    }
    sort(all(edges));
    dsu d; d.init(n);
    int ans = 0;
    for(auto i : edges)
    {
        if(d.find(i.second.first) != d.find(i.second.second))
        {
            d.merge(i.second.first, i.second.second);
            ans = i.first;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
