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

#define piipi pair<pair<int, int>, int>

void solve()
{
    setIO("lasers");
    int n, xl, yl, xb, yb; cin >> n >> xl >> yl >> xb >> yb;   
    vii mirrors(n);
    for(int i = 0; i < n; i++) cin >> mirrors[i].first >> mirrors[i].second;
    vi horiz, vert;
    set<int> seen, seen2;
    for(auto i : mirrors)  
    {
        if(seen.find(i.first) == seen.end()) 
        {
            seen.insert(i.first);
            vert.pb(i.first);
        }
        if(seen2.find(i.second) == seen2.end())
        {
            seen2.insert(i.second);
            horiz.pb(i.second);
        }
    }
    map<int, int> idxv, idxh;
    for(int i = 0; i < vert.size(); i++) idxv[vert[i]] = i;
    for(int i = 0; i < horiz.size(); i++) idxh[horiz[i]] = i;

    vector<vector<vii>> adj(1e5 + 5, vector<vii>(2)); // vertical lines, type 0; horizontal lines, type 1
    for(auto i : mirrors)
    {
        int xv = i.first, yv = i.second;
        int idxvert = idxv[xv], idxhoriz = idxh[yv];
        adj[idxvert][0].pb(mp(idxhoriz, 1));
        adj[idxhoriz][1].pb(mp(idxvert, 0));
    }
    // cout << endl;
    // printvec(vert); printvec(horiz);
    // for(auto i : idxv) cout << i.first << " " << i.second << endl;
    // cout << endl;
    // for(auto i : idxh) cout << i.first << " " << i.second << endl;
    queue<piipi> q;
    if(xl == xb || yl == yb) {cout << "0\n"; return;}
    if(idxv.find(xl) == idxv.end() && idxh.find(yl) == idxh.end()) 
    {
        cout << -1 << endl; return;
    }
    vector<vb> v(1e5 + 5, vb(2));
    if(idxv.find(xl) != idxv.end()) q.push(mp(mp(idxv[xl], 0), 0)), v[idxv[xl]][0] = 1;
    if(idxh.find(yl) != idxh.end()) q.push(mp(mp(idxh[yl], 1), 0)), v[idxh[yl]][1] = 1;
    while(!q.empty())
    {
        piipi curr = q.front(); q.pop();
        if(curr.first.second)
        {
            if(curr.first.first == idxh[yb])
            {
                cout << curr.second << endl; return;
            }
        }
        else 
        {
            if(curr.first.first == idxv[xb])
            {
                cout << curr.second << endl; return;
            }
        }
        for(auto adjnode : adj[curr.first.first][curr.first.second])
        {
            if(v[adjnode.first][adjnode.second]) continue;
            v[adjnode.first][adjnode.second] = 1;
            q.push(mp(adjnode, curr.second + 1));
        }
    }
    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}

