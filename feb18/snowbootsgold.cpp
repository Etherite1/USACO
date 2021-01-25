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
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.first << ", " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cerr << i << " "; cerr << endl;}
template <class T> void DBGpset(set<T> a) {for(T i : a) cerr << i.first << " " << i.second << endl;}

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

#define ff first
#define ss second

void solve()
{
    setIO("snowboots");
    int n, b; cin >> n >> b;
    vi a(n); for(int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, set<int>>> tiles; // this is how we will update pos array
    map<int, set<int>> tilesmap;
    for(int i = 0; i < n; i++) tilesmap[a[i]].insert(i);
    for(auto i : tilesmap) tiles.pb(i);
    sort(all(tiles));

    vector<pair<pii, int>> queries(b);
    vi ans(b);
    for(int i = 0; i < b; i++) // reads queries
    {
        cin >> queries[i].ff.ff >> queries[i].ff.ss;
        queries[i].ss = i;
    }
    sort(all(queries));

    vi pos(n); // sets possible array according to first query
    for(int i = 0; i < n; i++) if(a[i] <= queries[0].ff.ff) pos[i] = 1;

    multiset<pii> segs; // stores segments of zeroes from [l, r] inclusive
    auto cmp = [](pii a, pii b) {return (a.ff - a.ss) > (b.ff - b.ss);};
    multiset<pii, decltype(cmp)> lens(cmp); // stores zero segments but sorts by size, lens.begin() contains largest element

    int last = 0;
    bool inseg = 0;
    for(int i = 0; i < n; i++) // finds original chains of zeroes 
    {
        if(!pos[i])
        {
            if(!inseg)
            {
                inseg = 1;
                last = i;
            }
        }
        else
        {
            if(inseg)
            {
                inseg = 0;
                segs.insert(mp(i - 1, last));
                lens.insert(mp(i - 1, last));
            }
        }
    }
    if(lens.empty()) ans[queries[0].ss] = 1;
    else ans[queries[0].ss] = (*lens.begin()).ff - (*lens.begin()).ss + 1 < queries[0].ff.ss; // answer 0th query
    int tileidx = 0;
    for(int query = 1; query < b; query++)
    {
        int qdepth = queries[query].ff.ff, qstep = queries[query].ff.ss, qidx = queries[query].ss;
        while(tileidx < (int) tiles.size())
        {
            if(tiles[tileidx].ff <= qdepth) // if we can update
            {
                set<int> curr = tiles[tileidx].ss;
                for(int i : curr)
                {
                    // DBG3(i, tiles[tileidx].ff, qdepth); // position, depth
                    pos[i] = 1;
                  	auto it = segs.lower_bound(mp(i, -1));
                  	if(it == segs.end()) continue;
                    pii currseg = *it;
                    if(i < currseg.ss || i > currseg.ff) continue;
                  	
                  	// DBG3(currseg.ss, currseg.ff, i);
                    segs.erase(segs.find(currseg));
                    lens.erase(lens.find(currseg));
                    if(i != currseg.ss)
                    {
                        // cerr << "LEFTSEG " << currseg.ss << " " << i - 1 << endl;
                        segs.insert(mp(i - 1, currseg.ss));
                        lens.insert(mp(i - 1, currseg.ss));
                    }
                    if(i != currseg.ff)
                    {
                      	// cerr << "RIGHTSEG " << i + 1 << " " << currseg.ff << endl;
                        segs.insert(mp(currseg.ff, i + 1));
                        lens.insert(mp(currseg.ff, i + 1));
                    }
                }
                tileidx++;
            }
            else break;
        }
        // DBGvec(pos);
        // cout << "currquery " << qdepth << " " << qstep << endl;
        // for(auto i : segs) DBGpair(i, "seg");
        // for(auto i : lens) DBGpair(i, "len");
        if(lens.empty()) ans[qidx] = 1;
        else
        {
            // DBGpair((*lens.begin()), "lens begin");
            // DBG1(qstep);
            ans[qidx] = (*lens.begin()).ff - (*lens.begin()).ss + 1 < qstep; // update answer
        }
    }
    for(int i : ans) cout << i << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
