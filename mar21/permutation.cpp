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
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize

#ifdef Etherite_Local
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template <class T>
void DBGpair(T a, string s = "")
{
    cerr << s << (s == "" ? "" : ": ") << a.first << ", " << a.second << endl;
}
template <class T>
void DBGvec(vector<T> a)
{
    for (T i : a)
        cerr << i << " ";
    cerr << endl;
}
#else
#define DBG1(x)
#define DBG2(x, y)
#define DBG3(x, y, z)
#define DBG4(a, b, c, d)
template <class T>
void DBGpair(T a, string s = "")
{
    return;
}
template <class T>
void DBGvec(vector<T> &a) {}
#endif

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353
const ll INF = 1e9;

void setIO(string filename)
{
    if (fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

ll mul(ll x, ll y) { return (x * y) % MOD; }
ll add(ll x, ll y) { return (x + y) % MOD; }

ll triarea(pii a, pii b, pii c)
{
    ll x = a.first * b.second + b.first * c.second + c.first * a.second;
    ll y = a.second * b.first + b.second * c.first + c.second * a.first;
    return abs(x - y);
}

struct tri
{
    pii a, b, c;
    int ia, ib, ic;
    ll area;
    tri(pii A, pii B, pii C, int IA = -1, int IB = -1, int IC = -1) : a(A), b(B), c(C), ia(IA), ib(IB), ic(IC)
    {
        area = triarea(A, B, C);
    }
    void st()
    {
        if (ia > ib)
            swap(a, b), swap(ia, ib);
        if (ia > ic)
            swap(a, c), swap(ia, ic);
        if (ib > ic)
            swap(b, c), swap(ib, ic);
    }
    bool operator<(tri other) { return area < other.area; }
};

bool within(tri t, pii tar)
{
    pii a = t.a, b = t.b, c = t.c;
    ll x = triarea(a, b, tar), y = triarea(b, c, tar), z = triarea(a, c, tar);
    ll tot = triarea(a, b, c);
    return (x + y + z) == tot;
}

int tidx[100][100][100];

void solve()
{
    int n;
    cin >> n;
    vii pts(n);
    for (auto &i : pts)
        cin >> i.first >> i.second;

    memset(tidx, 0, sizeof(tidx));
    vector<tri> tris;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                tris.pb(tri(pts[i], pts[j], pts[k], i, j, k)), tidx[i][j][k] = tris.size() - 1;

    sort(all(tris));

    vvl dp(tris.size() + 50, vl(n + 50));

    for (tri t : tris)
    {
        int ininner = 0;
        vector<tri> to;
        for (int i = 0; i < n; i++)
        {
            if(!within(t, pts[i]))
            {
                tri nt1(pts[i], t.b, t.c, i, t.ib, t.ic); // triangles we could transition to next
                tri nt2(t.a, pts[i], t.c, t.ia, i, t.ic);
                tri nt3(t.a, t.b, pts[i], t.ia, t.ib, i);
                nt1.st(); nt2.st(); nt3.st();
                if (within(nt1, t.a)) to.pb(nt1);
                if (within(nt2, t.b)) to.pb(nt2);
                if (within(nt3, t.c)) to.pb(nt3);
            }
            else ininner++;
        }
        int curridx = tidx[t.ia][t.ib][t.ic];
        dp[curridx][ininner - 3] = add(dp[curridx][ininner - 3], 1);
        for(int i = ininner - 3; i > 0; i--) dp[curridx][i - 1] = add(dp[curridx][i - 1], mul(dp[curridx][i], i));
        for(auto nt : to)
        {
            int inouter = 0;
            int nextidx = tidx[nt.ia][nt.ib][nt.ic];
            for(int i = 0; i < n; i++) if(within(nt, pts[i])) inouter++;
            int tot = inouter - ininner - 1;
            for(int x = 0; x < n; x++)
            {
                dp[nextidx][x + tot] = add(dp[nextidx][x + tot], dp[tidx[t.ia][t.ib][t.ic]][x]);
            }
        }
    }
    tri fin = tris.back();
    ll ans = mul(6, dp[tidx[fin.ia][fin.ib][fin.ic]][0]);
    int cnt = 0;
    for(int i = 0; i < n; i++) if(within(fin, pts[i])) cnt++;
    if(cnt < n) ans = 0;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;

    for (int i = 1; i <= t; i++)
        solve();

    return 0;
}
