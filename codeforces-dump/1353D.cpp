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

struct compare
{
    bool operator() (pii a, pii b)
    {
        int lena = a.second - a.first + 1, lenb = b.second - b.first + 1;
        if(lena == lenb) return a.first < b.first;
        return lena > lenb;
    }  
};

void solve()
{
    int n; cin >> n;   
    set<pii, compare> pq;
    pq.insert(mp(0, n - 1));
    vi ans(n);
    rep(i, 1, n + 1)
    {
        pii curr = *pq.begin(); pq.erase(pq.begin());
        int l = curr.first, r = curr.second;
        int id = (l + r) / 2;
        ans[id] = i;
        if(l < id) pq.insert(mp(l, id - 1));
        if(id < r) pq.insert(mp(id + 1, r));
    }
    rep(i, 0, n) cout << ans[i] << " ";
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
