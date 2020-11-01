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
#define forrange(i, x) for(int i = 0; i < x; i++)
#define endl "\n"

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353
const int INF = 1e9;

bool cmp()
{
    return 0;
}

void solve()
{
    int n; cin >> n;
    vi c(n);
    forrange(i, n) cin >> c[i];

    ll mindist = 1e18;
    forrange(startpos, n)
    {
        ll currcount = 0; 
        ll idx = (startpos + 1) % n;
        vb v(n); v[startpos] = c[startpos] > 0;
        queue<int> q;
        forrange(i, c[startpos] - 1) q.push(startpos);
        while(idx != startpos)
        {
            forrange(i, c[idx]) q.push(idx);
            if(!v[idx]) 
            {
                if(!q.empty())
                {
                    int curr = q.front(); q.pop();
                    int halfcnt = (idx + n - curr) % n;
                    // cout << curr << " " << idx << " " << halfcnt << endl;
                    currcount += (halfcnt * halfcnt);
                    v[idx] = 1;
                }
            }
            idx = (idx + 1) % n;
        }
        while(!q.empty())
        {
            if(!v[idx])
            {
                int curr = q.front(); q.pop();
                v[idx] = 1;
                int halfcnt = (idx + n - curr) % n;
                // cout << curr << " " << idx << " " << halfcnt << endl;
                currcount += (halfcnt * halfcnt);
            }
            idx = (idx + 1) % n;
        }
        mindist = min(currcount, mindist);
        // cout << "CURRDIST " << currcount << " IDX " << startpos << endl;
    }
    cout << mindist << endl;
}

int main()
{
    fastio

    if(fopen("cbarn.in", "r"))
    {
        freopen("cbarn.in","r",stdin);
        freopen("cbarn.out","w",stdout);
    }

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
