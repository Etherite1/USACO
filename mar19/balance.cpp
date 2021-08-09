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
#define bitcount __builtin_popcount

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

ll add(ll a, ll b) {return (a + b) % MOD;}
ll sub(ll a, ll b)
{
    ll x = a - b;
    while(x < 0) x += MOD;
    return x;
}
ll mul(ll a, ll b) {return (a * b) % MOD;}
// ll divi(ll a, ll b) {return (a * modinv(b, MOD)) % MOD;}

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

ll compinv(vl &a)
{
    ll ans = 0, c0 = 0;
    for(int i = sz(a) - 1; i >= 0; i--)
    {
        if(a[i] == 0) c0++;
        else ans += c0;
    }
    return ans;
}

ll righttoleft(vl a, vl b, int n)
{
    vl prefa(n), suffb(n); 
    // prefa[i] = # of inversions in a[0...i], suffb[i] = # of inversions in b[i...n - 1]
    // should be correct bc i stressed with brute force
    prefa.back() = compinv(a), suffb[0] = compinv(b);
    ll c0 = 0, c1 = 0;
    for(auto i : b) c0 += !i;
    for(auto i : a) c1 += i;
    for(int i = n - 2; i >= 0; i--)
    {
        prefa[i] = prefa[i + 1];
        if(a[i + 1] == 0) prefa[i] -= c1;
        else c1--;
    }
    for(int i = 1; i < n; i++)
    {
        suffb[i] = suffb[i - 1];
        if(b[i - 1] == 1) suffb[i] -= c0;
        else c0--;
    }
    c0 = 0, c1 = 0;
    for(auto i : a) c0 += !i;
    for(auto i : b) c1 += i;
    ll can = min(c0, c1); // the most amount of 1's we can swap from b to a
    vl last0(can + 1), first1(can + 1); 
    // last0[i] = number of swaps it takes to make the last i elements of array a equal to 0
    // first1[i] = number of swaps it takes to make the first i elements of array b equal to 1
    set<ll> p0, p1; // p0 = positions of 0's in array a, p1 = positions of 1's in array b
    for(int i = 0; i < n; i++) 
    {
        if(a[i] == 0) p0.insert(i);
        if(b[i] == 1) p1.insert(i);
    }
    auto it0 = p0.rbegin();
    auto it1 = p1.begin();
    for(ll i = 1; i <= can; i++) // some maths
    {
        last0[i] = last0[i - 1] + (n - i) - *it0;
        first1[i] = first1[i - 1] + *it1 - (i - 1);
        it0++; it1++;
    }
    it0 = p0.rbegin(), it1 = p1.begin();
    ll ans = abs(compinv(a) - compinv(b)); // initialize to case where we perform no swaps
    for(ll shift = 1; shift <= can; shift++) // shift = number of 1's we move from array b to array a
    {
        int pospref = *it0 - 1, possuff = *it1 + 1; // prefix and suffix we use to calculate inversions
        ll invleft = 0, invright = 0;
        if(pospref >= 0) invleft = prefa[pospref];
        if(possuff < n) invright = suffb[possuff];
        ll cans = last0[shift] + first1[shift]; // number of swaps to make last elements 0 and first elements 1
        cans += shift * shift; // the shift^2 swaps required to swap 1's across the border
        cans += abs(invleft - invright); // finally, the |inv(a) - inv(b)|
        ans = min(ans, cans);
        it0++; it1++; // move our pointers
    }
    return ans;
}

ll lefttoright(vl a, vl b, int n)
{
    vl prefa(n), suffb(n); 
    // prefa[i] = # of inversions in a[0...i], suffb[i] = # of inversions in b[i...n - 1]
    // should be correct bc i stressed with brute force
    prefa.back() = compinv(a), suffb[0] = compinv(b);
    ll c0 = 0, c1 = 0;
    for(auto i : b) c0 += !i;
    for(auto i : a) c1 += i;
    for(int i = n - 2; i >= 0; i--)
    {
        prefa[i] = prefa[i + 1];
        if(a[i + 1] == 0) prefa[i] -= c1;
        else c1--;
    }
    for(int i = 1; i < n; i++)
    {
        suffb[i] = suffb[i - 1];
        if(b[i - 1] == 1) suffb[i] -= c0;
        else c0--;
    }
    c0 = 0, c1 = 0;
    for(auto i : a) c1 += i;
    for(auto i : b) c0 += !i;
    ll can = min(c0, c1);
    vl last1(can + 1), first0(can + 1); // last elements of array a are 1, first elements of array b are 0
    set<ll> p0, p1;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 1) p1.insert(i);
        if(b[i] == 0) p0.insert(i);
    }
    auto it1 = p1.rbegin(); 
    auto it0 = p0.begin();
    for(ll i = 1; i <= can; i++)
    {
        last1[i] = last1[i - 1] + (n - i) - *it1;
        first0[i] = first0[i - 1] + *it0 - (i - 1);
        it0++; it1++;
    }
    vl cnt1pref(n), cnt0suff(n);
    cnt1pref[0] = a[0]; for(int i = 1; i < n; i++) cnt1pref[i] = cnt1pref[i - 1] + a[i];
    cnt0suff.back() = !b.back(); for(int i = n - 2; i >= 0; i--) cnt0suff[i] = cnt0suff[i + 1] + !b[i];
    it1 = p1.rbegin(); it0 = p0.begin();
    ll ans = abs(compinv(a) - compinv(b));
    for(ll shift = 1; shift <= can; shift++)
    {
        int pospref = *it1 - 1, possuff = *it0 + 1;
        ll invleft = 0, invright = 0;
        if(pospref >= 0) invleft = prefa[pospref] + cnt1pref[pospref] * (n - pospref - 1);
        if(possuff < n) invright = suffb[possuff] + possuff * cnt0suff[possuff];
        ll cans = last1[shift] + first0[shift];
        cans += shift * shift;
        cans += abs(invleft - invright);
        ans = min(ans, cans);
        it0++; it1++;
    }
    return ans;
}

void solve()
{
    setIO("balance");
    ll n; cin >> n;
    vl a(n), b(n); for(auto &i : a) cin >> i; for(auto &i : b) cin >> i;
    if(compinv(a) == compinv(b)) {cout << "0\n"; return;}
    if(compinv(a) > compinv(b)) // reverse and flip bits
    {
        reverse(all(a)); reverse(all(b));
        swap(a, b);
        for(auto &i : a) i = !i;
        for(auto &i : b) i = !i;
    }
    ll ans = min(righttoleft(a, b, n), lefttoright(a, b, n));
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
