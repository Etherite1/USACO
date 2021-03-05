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

void solve()
{
    int n, k; cin >> n >> k;
    vector<set<int>> pos(n);   
    vii swaps(k); for(int i = 0; i < k; i++) cin >> swaps[i].first >> swaps[i].second, swaps[i].first--, swaps[i].second--;

    vvi adj(n);
    for(int i = 0; i < n; i++) pos[i].insert(i);
    vi a(n); iota(all(a), 0);
    for(int i = 0; i < k; i++)
    {
        swap(a[swaps[i].first], a[swaps[i].second]);
        pos[a[swaps[i].first]].insert(swaps[i].first);
        pos[a[swaps[i].second]].insert(swaps[i].second);
    }
    for(int i = 0; i < n; i++) 
    {
        adj[i].pb(a[i]);
        adj[a[i]].pb(i);
    }
    vvi comps;
    queue<int> q;
    vb v(n);
    for(int i = 0; i < n; i++)
    {
        if(v[i]) continue;
        v[i] = 1;
        vi currcomp;
        q.push(i);
        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            currcomp.pb(curr);
            for(auto adjnode : adj[curr])
            {
                if(v[adjnode]) continue;
                v[adjnode] = 1;
                q.push(adjnode);
            }
        }
        comps.pb(currcomp);
    }
    vi ans(n);
    for(auto comp : comps)
    {
        set<int> s;
        for(auto node : comp)
        {
            for(auto st : pos[node])
            {
                s.insert(st);
            }
        }
        for(auto node : comp) ans[node] = s.size();
    }
    for(auto i : ans) cout << i << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
