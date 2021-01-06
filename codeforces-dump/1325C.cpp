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
#define rep(i, a, b) for(int (i) = (a); (i) < (b); (i)++) 
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353
const int INF = 1e9;

template <class T> void printvec(vector<T> a)
{
    for(T i : a) cout << i << " ";
    cout << endl;
}

bool cmp()
{
    return 0;
}

void solve()
{
    int n; cin >> n;
    vi freq(n + 5);
    vii v;
    rep(i, 0, n - 1)
    {
        int x, y; cin >> x >> y;
        freq[x]++; freq[y]++;
        v.pb(mp(x, y));
    }
    int f = n - 2, b = 0;
    for(pii i : v)
    {
        if(freq[i.second] == 1 || freq[i.first] == 1)
        {
            cout << b << endl;
            b++;
        }
        else
        {
            cout << f << endl;
            f--;
        }
    }
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
    //cin >> t;

    while(t-- > 0) solve();
}
