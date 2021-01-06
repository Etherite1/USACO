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
    int n, x; cin >> n >> x;
    vector<set<int>> adj(n);
    for(int i = 0; i < n - 1; i++)
    {
        int l, r; cin >> l >> r; l--; r--;
        adj[l].insert(r);
        adj[r].insert(l);
    }   
    if(adj[x - 1].size() == 1 || n == 1) cout << "Ayush\n"; 
    else cout << (n % 2 == 1? "Ashish" : "Ayush") << endl;
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
