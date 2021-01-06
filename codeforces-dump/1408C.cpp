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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()
#define f first
#define s second
#define ld long double

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353
const int INF = 1e9;

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

bool cmp()
{
    return 0;
}

bool find(double mid, vector<ld> flags, int n, int l)
{
    ld curr1 = 0, currspeed1 = 1, time1 = 0;
    int target;
    for(int i = 0; i <= n; i++)
    {
        target = ((i == n)? l : flags[i]);
        ld req = (target - curr1) / currspeed1;
        curr1 = min(curr1 + min(req, mid - time1) * currspeed1, (ld) l);
        time1 += min(req, mid - time1);
        if(curr1 < target) break;
        currspeed1++;
    }
    ld curr2 = l, currspeed2 = 1, time2 = 0;
    for(int i = n - 1; i >= -1; i--)
    {
        target = (i == -1? 0 : flags[i]);
        ld req = (curr2 - target) / currspeed2;
        curr2 = max((ld) 0, curr2 - min(req, mid - time2) * currspeed2);
        time2 += min(req, mid - time2);
        if(curr2 > target) break;
        currspeed2++;
    }
    return curr1 <= curr2;
}

void solve()
{
    int n, l; cin >> n >> l;
    vector<ld> flags(n); rep(i, 0, n) cin >> flags[i];
    double left = 0, right = 1e9;
    int cnt = 0;
    while(right - left > 1e-7 && cnt < 1e5)
    {
        double mid = (right + left) / 2;
        if(find(mid, flags, n, l)) left = mid;
        else right = mid;
        cnt++;
    }
    cout << setprecision(15) << left << endl;
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
