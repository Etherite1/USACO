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

struct dsu
{
    vector<int> parent, sz;
    void init(int n)
    {
        parent = vector<int>(n + 1), sz = vector<int>(n + 1, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }  

    int find(int x)
    {
        if(parent[x] == x) return x;
        else return parent[x] = find(parent[x]);
    }

    void merge(int a, int b)
    {
        int roota = find(a), rootb = find(b);
        if(sz[roota] > sz[rootb]) swap(roota, rootb);
        parent[roota] = rootb; sz[rootb] += sz[roota];
    }
};

bool find(vector<pipii> edges, int mid, vi a, int n)
{
    dsu d; d.init(n);

    for(int i = 0; i < mid; i++) d.merge(edges[i].second.first, edges[i].second.second);
    for(int i = 0; i < n; i++) if(d.find(a[i]) != d.find(i)) return 0;
    return 1;
}

int main()
{
    fastio

    if(fopen("wormsort.in", "r"))
    {
        freopen("wormsort.in","r",stdin);
        freopen("wormsort.out","w",stdout);
    }

    int n, m; cin >> n >> m;

    vi a(n);
    for(int i = 0; i < n; i++) {cin >> a[i]; a[i]--;}

    vector<pipii> edges(m);
    for(int i = 0; i < m; i++)
    {
        int x, y, w; cin >> x >> y >> w;
        x--; y--;
        edges[i] = mp(w, mp(x, y));
    }

    sort(all(edges)); reverse(all(edges));

    int l = 0, r = m;
    while(r - l > 1)
    {
        int mid = (r + l) / 2;
        if(find(edges, mid, a, n)) r = mid;
        else l = mid;
    }
    cout << ((l == m - 1)? -1 : edges[l].first) << endl;
}
