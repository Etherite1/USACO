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

void solve()
{
    int n; cin >> n; vi a(n); rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) a[i]--;
    vvb s(n, vb(n));
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            char x; cin >> x;
            s[i][j] = x - '0';
        }
    }   
    vvi adj(n);
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if(s[i][j]) adj[i].pb(j);
        }
    }
    vvi comps;
    vb v(n);
    rep(i, 0, n)
    {
        if(v[i]) continue; v[i] = 1;
        queue<int> q; q.push(i);
        vi currcomp;
        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            currcomp.pb(curr);
            for(int adjnode : adj[curr])
            {
                if(v[adjnode]) continue; v[adjnode] = 1;
                q.push(adjnode);
            }
        }
        comps.pb(currcomp);
    }
    for(auto comp : comps)
    {
        sort(all(comp));
        int x = comp.size();
        rep(i, 0, x)
        {
            rep(j, i + 1, x)
            {
                if(a[comp[i]] > a[comp[j]]) swap(a[comp[i]], a[comp[j]]);
            }
        }
    }
    rep(i, 0, n) a[i]++;
    printvec(a);
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
