/* 
0-1 bfs implementation on a grid
use when the graph is binary weighted to find shortest paths
proof: http://www.usaco.org/index.php?page=viewproblem2&cpid=191 
*/

#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
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
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353
const int INF = 1e9;

int find(int sx, int sy, int n, vector<vb> grid, int a, int b)
{
    vvi dist(n, vi(n, INF));
    dist[sx][sy] = 0;
    deque<pii> dq;
    dq.pf({sx, sy});
    while(!dq.empty())
    {
        pii v = dq.front(); dq.pop_front();
        int x = v.first, y = v.second;
        for(int i = 0; i < 4; i++)
        {
            int currx = x + dx[i], curry = y + dy[i];
            if(currx < 0 || curry < 0 || currx >= n || curry >= n) continue;
            int w = grid[x][y] == grid[currx][curry]? a : b;
            if(dist[currx][curry] > dist[x][y] + w)
            {
                dist[currx][curry] = dist[x][y] + w;
                if(w == max(a, b)) dq.pb(mp(currx, curry));
                else dq.pf(mp(currx, curry));
            }
        }
    }
 
    int mx = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) mx = max(mx, dist[i][j]);
    return mx;
}
 
int main()
{
    fastio

    if(fopen("distant.in", "r"))
    {
        freopen("distant.in","r",stdin);
        freopen("distant.out","w",stdout);
    }
 
    int n, a, b; cin >> n >> a >> b;
 
    vector<vb> grid(n, vb(n, 0));
 
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
        {
            char x; cin >> x;
            grid[i][j] = x == '('; // binary weight graph
        }
 
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans = max(ans, find(i, j, n, grid, a, b));
        }
    }
    cout << ans << endl;
}
