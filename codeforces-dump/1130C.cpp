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

void solve()
{
    int n; cin >> n;
    pii start, end; cin >> start.first >> start.second >> end.first >> end.second;
    start.first--; start.second--; end.first--; end.second--;
    vvi grid(n, vi(n));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
        {
            char x; cin >> x; grid[i][j] = x - '0';
        }

    vii comp1, comp2;
    vvb v(n, vb(n));
    v[start.first][start.second] = 1;
    queue<pii> q; q.push(start);
    while(!q.empty())
    {
        pii curr = q.front(); q.pop();
        comp1.pb(curr);
        for(int i = 0; i < 4; i++)
        {
            int nx = curr.first + dx[i], ny = curr.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(v[nx][ny] || grid[nx][ny]) continue;
            v[nx][ny] = 1;
            q.push(mp(nx, ny));
        }
    }
    // for(auto i : comp1) cout << i.first << " " << i.second << endl;
    v = vvb(n, vb(n));
    v[end.first][end.second] = 1;
    q.push(end);
    while(!q.empty())
    {
        pii curr = q.front(); q.pop();
        comp2.pb(curr);
        for(int i = 0; i < 4; i++)
        {
            int nx = curr.first + dx[i], ny = curr.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(v[nx][ny] || grid[nx][ny]) continue;
            v[nx][ny] = 1;
            q.push(mp(nx, ny));
        }
    }
    bool samecomp = 0;
    for(pii i : comp1) if(i == end) samecomp = 1;
    if(samecomp) {cout << "0\n"; return;}
    else
    {
        int mindist = 1e5;
        for(pii i : comp1)
        {
            for(pii j : comp2)
            {
                int xdir = j.first - i.first, ydir = j.second - i.second;
                mindist = min(mindist, xdir * xdir + ydir * ydir);
            }
        }
        cout << mindist << endl;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
