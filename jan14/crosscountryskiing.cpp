#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define endl "\n"

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int n, m;
int grid[510][510], vis[510][510];
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
vector<pii> breaks;

bool chk(int dist)
{
    memset(vis, 0, sizeof(vis));
    queue<pii> q;
    q.push({breaks[0].first, breaks[0].second}); vis[breaks[0].first][breaks[0].second] = 1;
    while(!q.empty())
    {
        pii curr = q.front(); q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = curr.first + dx[i], ny = curr.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || (abs(grid[curr.first][curr.second] - grid[nx][ny]) > dist)) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    for(auto i : breaks)
    {
        if(!vis[i.first][i.second]) return 0;
    }
    return 1;
}

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> grid[i][j];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    {
        int x; cin >> x;
        if(x == 1) breaks.pb({i, j});
    }
    int l = -1, r = 2e9;
    while(r - l > 1)
    {
        int mid = (l + r) / 2;
        if(chk(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
