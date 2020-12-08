#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vb vector<bool>
#define vl vector<long long>
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pf push_front
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()
#define plpipii pair<long long, pair<int, pair<int, int>>>

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

class cmp
{
public:
    bool operator() (pipii a, pipii b)
    {
        return a.first > b.first;
    }
};

void solve()
{
    setIO("visitfj");
    int n, t; cin >> n >> t;
    vvi grid(n, vi(n));
    rep(i, 0, n) rep(j, 0, n) cin >> grid[i][j];
    priority_queue<plpipii, vector<plpipii>, greater<plpipii>> pq;
    vector<vector<vl>> dist(n, vector<vl>(n, vl(3, INF)));
    dist[0][0][0] = 0;
    pq.push({0, {0, {0, 0}}});
    while(!pq.empty())
    {
        plpipii next = pq.top(); pq.pop();
        ll curDist = next.first;
        int fields = next.second.first;
        pii coords = next.second.second;
        if(curDist > dist[coords.first][coords.second][fields]) continue;
        rep(i, 0, 4)
        {
            int x = coords.first + dx[i], y = coords.second + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= n) continue;
            int nextFields = (fields + 1) % 3;
            ll nextDist = curDist + t + (nextFields == 0 ? grid[x][y] : 0);
            if(nextDist < dist[x][y][nextFields])
            {
                dist[x][y][nextFields] = nextDist;
                pq.push({nextDist, {nextFields, {x, y}}});
            }
        }
    }
    cout << min({dist[n - 1][n - 1][0], dist[n - 1][n - 1][1], dist[n - 1][n - 1][2]}) << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
