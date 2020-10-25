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

bool cmp(pipii a, pipii b)
{
    return a.first < b.first;
}

int dist(pii a, pii b)
{
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

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

int main()
{
    fastio

    if(fopen("irrigation.in", "r"))
    {
        freopen("irrigation.in","r",stdin);
        freopen("irrigation.out","w",stdout);
    }

    int n, c; cin >> n >> c;

    vii fields(n);
    for(int i = 0; i < n; i++) cin >> fields[i].first >> fields[i].second;

    vector<pipii> dists;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int d = dist(fields[i], fields[j]);
            if(d < c) continue;
            dists.pb(mp(d, mp(i, j)));
        }
    }

    sort(all(dists), cmp);

    dsu d; d.init(n);

    ll cost = 0;
    for(pipii i : dists)
    {
        int a = i.second.first, b = i.second.second;
        if(d.find(a) == d.find(b)) continue;
        else
        {
            cost += i.first;
            d.merge(a, b);
        }
    }
    for(int i = 1; i < n; i++) 
        if(d.parent[i] != d.parent[i - 1]) 
        {
            cout << "-1\n"; return 0;
        }
    cout << cost << endl;
}
