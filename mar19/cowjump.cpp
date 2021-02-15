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
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.ff << ", " << a.ss << endl;}
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

// checks whether two line segments intersect
bool inter(long double p0_x, long double p0_y, long double p1_x, long double p1_y, long double p2_x, long double p2_y, long double p3_x, long double p3_y)
{
    long double s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     
    s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     
    s2_y = p3_y - p2_y;

    long double s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    if(s >= 0 && s <= 1 && t >= 0 && t <= 1) return 1;
    else return 0; // No collision
}

#define piipi pair<pii, int>
#define piipii pair<pii, pii>
#define ff first
#define ss second

vector<pair<pii, pii>> v;

int cntinter(int idx)
{
    int cnt = 0;
    pii p1 = v[idx].ff, p2 = v[idx].ss;
    for(int i = 0; i < v.size(); i++)
    {
        if(i == idx) continue;
        if(inter(p1.ff, p1.ss, p2.ff, p2.ss, v[i].ff.ff, v[i].ff.ss, v[i].ss.ff, v[i].ss.ss)) cnt++;
    }
    return cnt;
}

void solve()
{
    setIO("cowjump");
    int n; cin >> n;
    vector<piipii> events; // ((x, y), (l/r = 1/0, idx))
    for(int i = 0; i < n; i++) 
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        v.pb(mp(mp(a, b), mp(c, d)));
        events.pb(mp(mp(a, b), mp(1, i)));
        events.pb(mp(mp(c, d), mp(0, i)));
    }
    set<piipi> stl; // ((y, x), idx)
    auto cmp = [](piipi a, piipi b) {return a.ff.ff > b.ff.ff;};
    set<piipi, decltype(cmp)> lts(cmp);
    sort(all(events)); // sorted by x coord
    for(int i = 0; i < events.size(); i++)
    {
        pii curr = mp(events[i].ff.ss, events[i].ff.ff); int lor = events[i].ss.ff, idx = events[i].ss.ss;
        stl.insert(mp(curr, idx));
        lts.insert(mp(curr, idx));
        if(lor) // insert element
        {
            auto it = stl.upper_bound(mp(curr, idx)); // upper
            auto it2 = lts.upper_bound(mp(curr, idx)); // lower
            int upper = -1, lower = -1;
            if(it != stl.end()) upper = (*it).ss;
            if(it2 != lts.end()) lower = (*it2).ss;
            if(upper != -1)
            {
                pair<pii, pii> seg1 = v[idx], seg2 = v[upper];
                if(inter(seg1.ff.ff, seg1.ff.ss, seg1.ss.ff, seg1.ss.ss, seg2.ff.ff, seg2.ff.ss, seg2.ss.ff, seg2.ss.ss))
                {
                    int x = cntinter(idx), y = cntinter(upper);
                    if(x > y) cout << idx + 1 << endl;
                    else if(x < y) cout << upper + 1 << endl;
                    else cout << min(idx, upper) + 1 << endl;
                    return;
                }
            }
            if(lower != -1)
            {
                pair<pii, pii> seg1 = v[idx], seg2 = v[lower];
                if(inter(seg1.ff.ff, seg1.ff.ss, seg1.ss.ff, seg1.ss.ss, seg2.ff.ff, seg2.ff.ss, seg2.ss.ff, seg2.ss.ss))
                {
                    int x = cntinter(idx), y = cntinter(lower);
                    if(x > y) cout << idx + 1 << endl;
                    else if(x < y) cout << lower + 1 << endl;
                    else cout << min(idx, lower) + 1 << endl;
                    return;
                }
            }
        }
        else // remove element
        {
            stl.erase(mp(curr, idx));
            lts.erase(mp(curr, idx));
            auto it = stl.upper_bound(mp(curr, idx));
            auto it2 = lts.upper_bound(mp(curr, idx)); 
            int upper = -1, lower = -1;
            if(it != stl.end()) upper = (*it).ss;
            if(it2 != lts.end()) lower = (*it2).ss;
            if(upper != -1 && lower != -1)
            {
                pair<pii, pii> seg1 = v[lower], seg2 = v[upper];
                if(inter(seg1.ff.ff, seg1.ff.ss, seg1.ss.ff, seg1.ss.ss, seg2.ff.ff, seg2.ff.ss, seg2.ss.ff, seg2.ss.ss))
                {
                    int x = cntinter(lower), y = cntinter(upper);
                    if(x > y) cout << lower + 1 << endl;
                    else if(x < y) cout << upper + 1 << endl;
                    else cout << min(lower, upper) + 1 << endl;
                    return;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
