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

ll find(int x, int y, string s)
{
    vvi dp(10, vi(10));
    for(int i = 0; i < 10; i++)
    {
        vi tempdp(10, 1e9);
        tempdp[(i + x) % 10] = 1;
        tempdp[(i + y) % 10] = 1;
        int iter = 0;
        while(iter < 100)
        {
            for(int k = 0; k < 10; k++)
            {
                tempdp[(k + x) % 10] = min(tempdp[(k + x) % 10], tempdp[k] + 1);
                tempdp[(k + y) % 10] = min(tempdp[(k + y) % 10], tempdp[k] + 1);
            }
            iter++;
        }
        dp[i] = tempdp;
    }
    ll cnt = 0;
    for(int i = 0; i < s.size() - 1; i++)
    {
        int c1 = s[i] - '0', c2 = s[i + 1] - '0';
        if(dp[c1][c2] == 1e9) return -1;
        else cnt += dp[c1][c2] - 1;
    }
    return cnt;
}

void solve()
{
    string s; cin >> s;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << find(i, j, s) << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
