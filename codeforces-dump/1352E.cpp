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
    int n; cin >> n; vi a(n); for(int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> m;
    for(int i : a) m[i]++;
    int ans = 0;
    for(int l = 0; l < n; ++l)
    {
        int sum = 0;
        for(int r = l; r < n; ++r)
        {
            sum += a[r];
            if(l == r) continue;
            if(sum <= n) 
            {
                ans += m[sum];
                m.erase(sum);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    fastio

    if(fopen("file.in", "r"))
    {
        freopen("file.in","r",stdin);
        freopen("file.out","w",stdout);
    }

    int t = 1;
    cin >> t;

    while(t-- > 0) solve();
}
