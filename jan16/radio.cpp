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

pii nxt(pii curr, char move)
{
    if(move == 'W') curr.first--;
    else if(move == 'E') curr.first++;
    else if(move == 'N') curr.second++;
    else curr.second--;
    return curr;
}

int dst(pii a, pii b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void solve()
{
    setIO("radio");
    int n, m; cin >> n >> m;
    pii fj, bess; cin >> fj.first >> fj.second >> bess.first >> bess.second;
    string fjpath, besspath; cin >> fjpath >> besspath;   
    vvi dp(n + 1, vi(m + 1));
    vvi dist(n + 1, vi(m + 1));
    for(int i = 0; i < n; i++)
    {
        pii besstmp = bess;
        for(int j = 0; j < m; j++)
        {
            dist[i][j] = dst(fj, besstmp);
            besstmp = nxt(besstmp, besspath[j]);
        }
        dist[i][m] = dst(fj, besstmp);
        fj = nxt(fj, fjpath[i]);
    }
    for(int j = 0; j < m; j++) 
    {
        dist[n][j] = dst(fj, bess);
        bess = nxt(bess, besspath[j]);
    }
    dist[n][m] = dst(fj, bess);
    dist[0][0] = 0;
    
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = 0; continue;
            }
            dp[i][j] = dist[i][j];
            int o = 1e9;
            if(i > 0) o = min(o, dp[i - 1][j]);
            if(j > 0) o = min(o, dp[i][j - 1]);
            if(i > 0 && j > 0) o = min(o, dp[i - 1][j - 1]);
            dp[i][j] += o;
        }
    }
    // for(auto i : dp) printvec(i);
    cout << dp[n][m] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
