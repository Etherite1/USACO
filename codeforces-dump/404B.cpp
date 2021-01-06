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

ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}

template <class T> void printvec(vector<T> a)
{
    for(T i : a) cout << i << " ";
    cout << endl;
}

ll aceil(ll num, ll denom)
{
    return (num + denom - 1) / denom;
}

bool cmp()
{
    return 0;
}

void solve()
{
    ld side, d, n; cin >> side >> d >> n;

    ld xpos = 0, ypos = 0;
    bool east = 1, north = 0, south = 0, west = 0;
    for(int i = 0; i < n; i++)
    {
        ld currdist = fmod(d, 4 * side);
        while(true)
        {
            if(currdist <= 1e-5) break;
            if(east)
            {
                if(xpos + currdist >= side)
                {
                    currdist -= (side - xpos);
                    xpos = side;
                    east = 0, north = 1;
                }
                else xpos += currdist, currdist = 0;
            }
            else if(north)
            {
                if(ypos + currdist >= side)
                {
                    currdist -= (side - ypos);
                    ypos = side;
                    north = 0, west = 1;
                }
                else ypos += currdist, currdist = 0;
            }
            else if(west)
            {
                if(xpos - currdist <= 0)
                {
                    currdist -= xpos;
                    xpos = 0;
                    west = 0, south = 1;
                }
                else xpos -= currdist, currdist = 0;
            }
            else if(south)
            {
                if(ypos - currdist <= 0)
                {
                    currdist -= ypos;
                    ypos = 0;
                    south = 0, east = 1;
                }
                else ypos -= currdist, currdist = 0;
            }
        }
        cout << setprecision(10) << xpos << " " << ypos << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
