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
    vii a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    for(int i = 1; i < n; i++)
    {
        if(a[i].first < a[i - 1].first || a[i].second < a[i - 1].second)
        {
            cout << "NO\n"; return;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i].second > a[i].first)
        {
            cout << "NO\n"; return;
        }
    }
    for(int i = 1; i < n; i++)
    {
        if(a[i].second > a[i - 1].second)
        {
            if(a[i].first - a[i - 1].first < a[i].second - a[i - 1].second)
            {
                cout << "NO\n"; return;
            }
        }
    }
    cout << "YES\n";
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
