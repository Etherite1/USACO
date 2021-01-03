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
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pf push_front
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i, begin, end) for(int i = begin; i < end; i++)
#define brep(i, end, begin) for(int i = end; i > begin; i--)
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

vi xs, ys;

bool cmpe(int a, int b)
{
    return ys[a] < ys[b];
}

bool cmpn(int a, int b)
{
    return xs[a] < xs[b];
}

void solve()
{
    int n; cin >> n;
    vi east, north;
    xs.resize(n); ys.resize(n);
    rep(i, 0, n)
    {
        char x; cin >> x;
        if(x == 'E') east.pb(i);
        else north.pb(i);
        cin >> xs[i] >> ys[i];
    }
    sort(all(east), cmpe); sort(all(north), cmpn);
    vb stopped(n); vi amt(n);
    for(int i : east)
    {
        for(int j : north)
        {
            if(!stopped[i] && !stopped[j] && xs[j] > xs[i] && ys[i] > ys[j])
            {
                if(xs[j] - xs[i] > ys[i] - ys[j])
                {
                    stopped[i] = 1;
                    amt[j] += amt[i] + 1;
                }
                else if(ys[i] - ys[j] > xs[j] - xs[i])
                {
                    stopped[j] = 1;
                    amt[i] += amt[j] + 1;
                }
            }
        }
    }
    rep(i, 0, n) cout << amt[i] << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
