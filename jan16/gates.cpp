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

struct Point
{
    int x, y;
    Point(int cx, int cy)
    {
        x = cx; y = cy;
    }
};


int main()
{
    fastio

    freopen("gates.in","r",stdin);
    freopen("gates.out","w",stdout);

    int n; cin >> n;
    string s; cin >> s;
    int nn = 2005;
    vector<vector<bool>> isfence(nn, vb(nn));
    int cx = 1002, cy = 1002;
    isfence[cx][cy] = true;
    for(char i : s)
    {
        int dirx = 0, diry = 0;
        if(i == 'N') dirx = -1;
        else if(i == 'S') dirx = 1;
        else if(i == 'W') diry = -1;
        else diry = 1;
        for(int a = 0; a < 2; a++)
        {
            cx += dirx; cy += diry;
            isfence[cx][cy] = 1;
        }
    }

    int ret = -1; 
    for(int i = 0; i < nn; i++)
    {
        for(int j = 0; j < nn; j++)
        {
            if(isfence[i][j]) continue;
            isfence[i][j] = 1;
            ret++;
            queue<Point> q;
            q.push(Point(i, j));
            while(!q.empty())
            {
                Point curr = q.front(); q.pop();
                for(int k = 0; k < 4; k++)
                {
                    int nx = curr.x + dx[k], ny = curr.y + dy[k];
                    if(nx >= 0 && nx < nn && ny >= 0 && ny < nn && !isfence[nx][ny])
                    {
                        isfence[nx][ny] = true;
                        q.push(Point(nx, ny));
                    }
                }
            }
        }
    }
    cout << ret << endl;
}
