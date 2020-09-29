#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vb vector<bool>
#define vl vector<long long>
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353

int main()
{
    fastio

    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");

    int n, b; fin >> n >> b;
    vi path(n);
    vii boots(n);

    for(int i = 0; i < n; i++) fin >> path[i];
    for(int i = 0; i < b; i++) fin >> boots[i].first >> boots[i].second;

    vector<vector<bool>> dp(b);
    for(int i = 0; i < b; i++)
    {
        vb a(n);
        dp[i] = a;
    }

    dp[0][0] = true;
    for(int i = 0; i < b; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(path[j] > boots[i].first) 
            {
                dp[i][j] = false;
                continue;
            }
            for(int k = 0; k < j; k++)
            {
                if(dp[i][k] && k + boots[i].second >= j) dp[i][j] = true;
            }
            for(int k = 0; k < i; k++)
            {
                if(dp[k][j]) dp[i][j] = true;
            }

            if(j == n - 1 && dp[i][j])
            {
                fout << i << endl;
                return 0;
            }
        }
    }
}
