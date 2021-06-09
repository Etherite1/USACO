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

struct dsu
{
    vector<vector<pii>> parent;
    vector<vector<int>> sz;
    void init(int n)
    {
        parent = vector<vector<pii>>(n + 10, vector<pii>(n + 10)), sz = vector<vector<int>>(n + 10, vector<int>(n + 10, 1));
        for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) parent[i][j] = {i, j};
    }  

    pii find(pii x)
    {
        if(parent[x.first][x.second] == x) return x;
        else return parent[x.first][x.second] = find(parent[x.first][x.second]);
    }

    void merge(pii a, pii b)
    {
        pii roota = find(a), rootb = find(b);
        if(sz[roota.first][roota.second] > sz[rootb.first][rootb.second]) swap(roota, rootb);
        parent[roota.first][roota.second] = rootb; sz[rootb.first][rootb.second] += sz[roota.first][roota.second];
    }
};

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

const int N = 510;
int grid[N][N];

#define edge pair<int, pair<pii, pii>>

void solve()
{
    setIO("tractor2");
    int n; cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> grid[i][j];
    // {cost, {pii, pii}}
    vector<edge> edges;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx[dir], ny = j + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                edges.pb({abs(grid[i][j] - grid[nx][ny]), {{i, j}, {nx, ny}}});
            }
        }
    }
    sort(edges.begin(), edges.end());
    dsu d; d.init(n);
    int req = (n * n + 1) / 2;
    for(auto e : edges)
    {
        if(d.find(e.second.first) == d.find(e.second.second)) continue;
        d.merge(e.second.first, e.second.second);
        pii p1 = d.find(e.second.first), p2 = d.find(e.second.second);
        if(max(d.sz[p1.first][p1.second], d.sz[p2.first][p2.second]) >= req)
        {
            cout << e.first << endl;
            return;
        }
    }
}   

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
