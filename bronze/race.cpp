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

int k, n;

bool cmp()
{
    return 0;
}

void solve(int query)
{
    int lhs = 0, rhs = 0, t = 0;
    for(int i = 1; ; i++)
    {
        lhs += i;
        t++;
        if(lhs + rhs >= k) 
        {
            cout << t << endl; return;
        }
        if(i >= query)
        {
            rhs += i;
            t++;
            if(lhs + rhs >= k) 
            {
                cout << t << endl; return;
            }
        }
    }
}

int main()
{
    fastio

    if(fopen("race.in", "r"))
    {
        freopen("race.in","r",stdin);
        freopen("race.out","w",stdout);
    }
    int t;
    cin >> k >> t;

    while(t-- > 0) 
    {
        int q; cin >> q; solve(q);
    }
}
