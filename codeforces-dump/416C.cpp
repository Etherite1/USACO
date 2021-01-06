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

vii vis, tab;
bool cmp1(int a, int b)
{
    return vis[a].first > vis[b].first;
}

void solve()
{
    int n; cin >> n;
    vis.resize(n);
    rep(i, 0, n) cin >> vis[i].second >> vis[i].first;
    int k; cin >> k;
    tab.resize(k); rep(i, 0, k) cin >> tab[i].first;
    rep(i, 0, k) tab[i].second = i;
    
    vi a(n); iota(all(a), 0);
    sort(all(a), cmp1);
    sort(all(tab));

    vii ans;
    rep(i, 0, n)
    {
        if(tab.size() == 0) break;
        pii curr = vis[a[i]];
        if(curr.second > tab[tab.size() - 1].first) continue;
        int l = 0;
        rep(j, 0, tab.size())
        {
            if(tab[j].first >= curr.second)
            {
                l = j;
                break;
            }
        }
        ans.pb(mp(a[i], tab[l].second));
        tab.erase(tab.begin() + l);
    }
    int cost = 0;
    for(auto i : ans) cost += vis[i.first].first;
    cout << ans.size() << " " << cost << endl;
    for(auto i : ans) cout << i.first + 1 << " " << i.second + 1 << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
