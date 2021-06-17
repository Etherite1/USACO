#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
#define rall(x) (x).rbegin(),(x).rend()
#define endl "\n"
#define rsz resize
#define sz(a) ((int)(a).size())

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update > oset; // find_by_order, order_of_key
#define fbo find_by_order
#define ook order_of_key

#ifdef Etherite_Local
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
#define DBG5(a, b, c, d, e) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << " " << (#e) << ": " << a << " " << b << " " << c << " " << d << " " << e << endl;
#define DBG6(a, b, c, d, e, f) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << " " << (#e) << " " << (#f) << ": " << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.first << ", " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cerr << i << " "; cerr << endl;}
template <class T> void DBGset(set<T> a){for(T i : a) cerr << i << " "; cerr << endl;}
mt19937 rnd(228);
#else
#define DBG1(x)
#define DBG2(x, y)
#define DBG3(x, y, z)
#define DBG4(a, b, c, d)
#define DBG5(a, b, c, d, e)
#define DBG6(a, b, c, d, e, f)
template<class T> void DBGpair(T a, string s = "") {return;}
template <class T> void DBGvec(vector<T> &a){}
template <class T> void DBGset(set<T> &a){}
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

int bitcount(int n)
{
    int cnt = 0;
    for(int i = 0; i < 25; i++)
    {
        if(n & (1 << i)) cnt++;
    }
    return cnt;
}

void solve()
{
    setIO("partition");
    int n, fences; cin >> n >> fences;
    vvi values(n, vi(n)); for(auto &i : values) for(auto &j : i) cin >> j;
    int ans = 1e9;
    for(int i = 0; i < (1 << (n - 1)); i++)
    {
        if(bitcount(i) > fences) continue;
        vi set(n);
        for(int j = 0; j < n - 1; j++) if(i & (1 << j)) set[j + 1] = 1;
        int l = 0, r = 1e9;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            bool ok = 1;
            int rem = fences - bitcount(i), cnt = 0;
            vi sections(bitcount(i) + 1);
            for(int j = 0; j < n; j++)
            {
                cnt += set[j];
                sections[cnt] += values[j][0];
            }
            for(int j = 1; j < n; j++)
            {
                for(int k = 0; k < sz(sections); k++) if(sections[k] > mid) {ok = 0; break;}
                cnt = 0;
                for(int k = 0; k < n; k++)
                {
                    cnt += set[k];
                    sections[cnt] += values[k][j];
                }
                bool setline = 0;
                for(int k = 0; k < sz(sections); k++) if(sections[k] > mid) {setline = 1; break;}
                cnt = 0;
                if(setline && rem > 0)
                {
                    rem--;
                    fill(all(sections), 0);
                    for(int k = 0; k < n; k++)
                    {
                        if(set[k]) cnt++;
                        sections[cnt] += values[k][j];
                    }
                    for(int k = 0; k < sz(sections); k++) if(sections[k] > mid) {ok = 0; break;}
                }
                else
                {
                    for(int k = 0; k < sz(sections); k++) if(sections[k] > mid) {ok = 0; break;}
                }
            }
            if(ok) r = mid - 1;
            else l = mid + 1;
        }
        ans = min(ans, l);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
