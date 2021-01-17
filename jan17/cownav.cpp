
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


char dir[] = {'R', 'L', 'D', 'U'}; // E W N S
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

struct state
{
    int i, j, k, l, m, n;
    state(int ii, int jj, int kk, int lll, int mm, int nn)
    {
        i = ii; 
        j = jj;
        k = kk;
        l = lll;
        m = mm;
        n = nn;
    }
};

vvb grid;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0}; 
int n;

pii fwd(int a, int b, int dir) // 0 is east, 1 is west, 2 is north, 3 is south
{
    if(a == 0 && b == n - 1) return mp(a, b);
    int oa = a, ob = b;
    a += dx[dir]; b += dy[dir];
    a = max(0, a); b = max(0, b);
    a = min(a, n - 1); b = min(b, n - 1);
    if(grid[a][b]) return mp(a, b);
    else return mp(oa, ob);
}

void solve()
{
    setIO("cownav");
    cin >> n;
    grid = vvb(n, vb(n));
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for(int j = 0; j < n; j++) grid[i][j] = s[j] == 'E';
    }
    //state:
    // {i, j} is position, k is direction currently if i started from north
    // {l, m} is position, n is direction currently if i started from east
    // 0 is east, 1 is west, 2 is north, 3 is south
    int dp[21][21][4][21][21][4];
    bool v[21][21][4][21][21][4];
    for(int i = 0; i <= 20; i++) 
        for(int j = 0; j <= 20; j++)
            for(int k = 0; k < 4; k++)
                for(int l = 0; l <= 20; l++)
                    for(int m = 0; m <= 20; m++)
                        for(int n = 0; n < 4; n++)
                            dp[i][j][k][l][m][n] = 1e9, v[i][j][k][l][m][n] = 0;
                            
    map<int, int> turnleft, turnright;
    turnleft[0] = 2; turnleft[1] = 3; turnleft[2] = 1; turnleft[3] = 0;
    turnright[0] = 3; turnright[1] = 2; turnright[2] = 0; turnright[3] = 1;
    
    queue<pair<int, state>> q;
    v[n - 1][0][2][n - 1][0][0] = 1;
    dp[n - 1][0][2][n - 1][0][0] = 0;
    v[n - 1][0][0][n - 1][0][2] = 1;
    dp[n - 1][0][0][n - 1][0][2] = 0;
    q.push(mp(0, state(n - 1, 0, 2, n - 1, 0, 0)));
    q.push(mp(0, state(n - 1, 0, 0, n - 1, 0, 2)));
    
    while(!q.empty())
    {
        pair<int, state> curr = q.front(); q.pop();
        state s = curr.second;
        if(s.i == 0 && s.j == n - 1 && s.l == 0 && s.m == n - 1) 
        {
            cout << curr.first << endl; return;
        }

        //turn left
        if(!v[s.i][s.j][turnleft[s.k]][s.l][s.m][turnleft[s.n]])
        {
            v[s.i][s.j][turnleft[s.k]][s.l][s.m][turnleft[s.n]] = 1;
            dp[s.i][s.j][turnleft[s.k]][s.l][s.m][turnleft[s.n]] = curr.first + 1;
            q.push(mp(curr.first + 1, state(s.i, s.j, turnleft[s.k], s.l, s.m, turnleft[s.n])));
        }

        //turn right
        if(!v[s.i][s.j][turnright[s.k]][s.l][s.m][turnright[s.n]])
        {
            v[s.i][s.j][turnright[s.k]][s.l][s.m][turnright[s.n]] = 1;
            dp[s.i][s.j][turnright[s.k]][s.l][s.m][turnright[s.n]] = curr.first + 1;
            q.push(mp(curr.first + 1, state(s.i, s.j, turnright[s.k], s.l, s.m, turnright[s.n])));
        }

        //move forward
        pii nor = fwd(s.i, s.j, s.k), east = fwd(s.l, s.m, s.n);

        if(!v[nor.first][nor.second][s.k][east.first][east.second][s.n])
        {
            v[nor.first][nor.second][s.k][east.first][east.second][s.n] = 1;
            dp[nor.first][nor.second][s.k][east.first][east.second][s.n] = curr.first + 1;
            q.push(mp(curr.first + 1, state(nor.first, nor.second, s.k, east.first, east.second, s.n)));
        }

    }   
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    // cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
