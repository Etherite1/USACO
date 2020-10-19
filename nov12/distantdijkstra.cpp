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
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define INF 1e9
#define f first
#define s second

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353

int n, a, b;

int find(vvi grid, int startx, int starty)
{
    vector<vector<bool>> v(n, vb(n));
    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;

    vvi dist(n, vi(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dist[i][j] = INF;
    dist[startx][starty] = 0;

    pq.push({0, {startx, starty}});
    while(!pq.empty())
    {
        pipii top = pq.top(); pq.pop();
        int x = top.s.f;
        int y = top.s.s;

        v[x][y] = true;
        for(int i = 0; i < 4; i++)
        {
            if(x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= n) continue;
            if(v[x + dx[i]][y + dy[i]]) continue;
            int w = (grid[x + dx[i]][y + dy[i]] == grid[x][y])? a : b;
            if(dist[x][y] + w < dist[x + dx[i]][y + dy[i]])
            {
                dist[x + dx[i]][y + dy[i]] = dist[x][y] + w; 
                pq.push(mp(dist[x][y] + w, mp(x + dx[i], y + dy[i])));
            }

        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans = max(ans, dist[i][j]);
    return ans;  
}

int main()
{
    fastio

    ifstream fin("distant.in");
    ofstream fout("distant.out");

    fin >> n >> a >> b;
    vvi grid(n, vi(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char x; fin >> x;
            if(x == '(') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans = max(ans, find(grid, i, j));

    fout << ans << endl;
}
