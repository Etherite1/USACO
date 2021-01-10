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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
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

int n, m;

#define pipipii pair<int, pair<int, pair<int, int>>>

pipipii state(int a, int b, int c, int d)
{
    return mp(a, mp(b, mp(c, d)));
}

vvi grid;

bool go(int x, int y, int s)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    if(grid[x][y] == 0) return 0;
    if(grid[x][y] == 3) return s;
    return 1;
}

void solve()
{
    setIO("dream");
    cin >> n >> m;
    grid = vvi(n, vi(m)); vector<vvi> v(n + 1, vvi(m + 1, vi(2, 1e9)));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> grid[i][j];
    
    priority_queue<pipipii, vector<pipipii>, greater<pipipii>> q;
    q.push(state(0, 0, 0, 0));
    while(!q.empty())
    {
        pipipii curr = q.top(); q.pop();
        int d = curr.first, x = curr.second.first, y = curr.second.second.first, o = curr.second.second.second;
        if(x == n - 1 && y == m - 1) {cout << d << endl; return;}
        if(v[x][y][o] != 1e9) continue;
        v[x][y][o] = d;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i], nd = d + 1, no = o;
            if(!go(nx, ny, o)) continue;
            if(grid[nx][ny] == 2) no = 1;
            else if(grid[nx][ny] == 4)
            {
                no = 0;
                while(go(nx + dx[i], ny + dy[i], o) && grid[nx][ny] == 4)
                {
                    nx += dx[i], ny += dy[i]; nd++;
                }
            }
            if(v[nx][ny][no] > nd) q.push(state(nd, nx, ny, no));
        }
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
