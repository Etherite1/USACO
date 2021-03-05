#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vi vector<int>
#define pb push_back
#define mp make_pair

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vvi grid(5000, vi(5000));

bool cntadj(int x, int y)
{
    int ans = 0;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(grid[nx][ny]) ans++;
    }
    return ans == 3;
}

pii findadj(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(!grid[nx][ny]) return mp(nx, ny);
    }
    return mp(0, 0);
}

void solve()
{
    int n; cin >> n;
    vii pts;
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y; x += 1000; y += 1000;
        pts.pb(mp(x, y));
    }
    set<pii> added;
    for(int i = 0; i < n; i++)
    {
        if(added.find(pts[i]) != added.end())
        {
            added.erase(pts[i]);
            cout << added.size() << "\n"; continue;
        }
        grid[pts[i].first][pts[i].second] = 1;
        set<pii> inq;
        queue<pii> q;
        q.push(pts[i]);
        inq.insert(pts[i]);
        while(!q.empty())
        {
            pii c = q.front(); q.pop();
            inq.erase(c);
            if(cntadj(c.first, c.second))
            {
                pii x = findadj(c.first, c.second);
                grid[x.first][x.second] = 1;
                if(inq.find(x) == inq.end()) q.push(x), inq.insert(x);
                added.insert(x);
            }
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = c.first + dx[dir], ny = c.second + dy[dir];
                if(!grid[nx][ny]) continue;
                if(cntadj(nx, ny) && (inq.find(mp(nx, ny)) == inq.end())) q.push(mp(nx, ny)), inq.insert(mp(nx, ny));
            }
        }
        cout << added.size() << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();
}
