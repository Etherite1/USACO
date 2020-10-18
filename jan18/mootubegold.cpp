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

const int MAXN = 100001;

vector<int> parent(MAXN);
vector<int> sz(MAXN);

void initialize()
{
    for(int i = 0; i < MAXN; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int x)
{
    if(parent[x] == x) return x;
    else
    {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void merge(int a, int b)
{
    int roota = find(a), rootb = find(b);
    if(sz[roota] > sz[rootb]) swap(roota, rootb);
    parent[roota] = rootb;
    sz[rootb] += sz[roota];
}

bool cmp(pipii a, pipii b)
{
    return a.first > b.first;
}

bool cmp2(pipii a, pipii b)
{
    return a.second.first < b.second.first;
}

int main()
{
    fastio

    if(fopen("mootube.in", "r"))
    {
        freopen("mootube.in","r",stdin);
        freopen("mootube.out","w",stdout);
    }

    int n, q; cin >> n >> q;

    vector<pipii> edges(n);
    for(int i = 0; i < n - 1; i++) cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;

    sort(all(edges), cmp);

    vector<pipii> queries(q);
    for(int i = 0; i < q; i++) cin >> queries[i].second.first >> queries[i].second.second;
    for(int i = 0; i < q; i++) queries[i].first = i;
    sort(all(queries), cmp2);
    reverse(all(queries));

    vi ans(q);

    initialize();

    int edgeidx = 0;
    for(int i = 0; i < q; i++)
    {
        pipii query = queries[i];
        for(int j = edgeidx; j < n; j++)
        {
            pipii curredge = edges[j];
            if(curredge.first >= query.second.first)
            {
                merge(curredge.second.first, curredge.second.second);
            }
            else
            {
                edgeidx = j;
                break;
            }
        }
        ans[query.first] = sz[find(query.second.second)] - 1;
    }

    for(int i : ans) cout << i << endl;

}
