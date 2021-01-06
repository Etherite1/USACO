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
    vi b(n + 1);
    for(int i = 0; i < n; i++) cin >> b[i + 1];

    vi a(2 * n + 1);

    set<int> s; for(int i = 1; i <= n; i++) s.insert(b[i]);

    set<int> unused; for(int i = 1; i <= 2 * n; i++) if(s.find(i) == s.end()) unused.insert(i);

    for(int i = 1; i <= n; i++)
    {
        a[2 * i - 1] = b[i];
        for(int j : unused)
        {
            if(j < b[i]) continue;
            a[2 * i] = j;
            unused.erase(j);
            break;
        }
        if(a[2 * i] == 0)
        {
            cout << "-1\n"; return;
        }
    }
    for(int i = 1; i <= 2 * n; i++) cout << a[i] << " ";
    cout << endl;

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
