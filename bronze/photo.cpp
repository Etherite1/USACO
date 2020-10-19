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


bool cmp()
{
    return 0;
}

void solve()
{
    int n; cin >> n;
    vi a(n - 1);
    for(int i = 0; i < n - 1; i++) cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        set<int> s;
        vi curr;
        curr.pb(i);
        s.insert(i);
        for(int j = 0; j < n - 1; j++)
        {
            int x = a[j] - curr[j];
            if(x <= 0) break;
            if(s.find(x) != s.end()) break;
            else
            {
                s.insert(x);
                curr.pb(x);
            }
        }
        string ans;
        if(curr.size() == n)
        {
            for(int i : curr) 
            {
                if(ans.size() > 0) ans += " ";
                ans += to_string(i);
            }
            cout << ans;
            return;
        }
    }
}

int main()
{
    fastio

    if(fopen("photo.in", "r"))
    {
        freopen("photo.in","r",stdin);
        freopen("photo.out","w",stdout);
    }

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
