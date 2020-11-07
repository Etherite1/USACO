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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 2019201997; //998244353
const ll INF = 1e17;

const ll multx = 2019201913;
const ll multy = 2019201949;

struct dsu
{
    vector<int> parent, sz;
    void init(int n)
    {
        parent = vector<int>(n + 1), sz = vector<int>(n + 1, 1); for(int i = 0; i <= n; i++) parent[i] = i;
    }  
    int find(int x)
    {
        return (parent[x] == x? x : parent[x] = find(parent[x]));
    }
    void merge(int a, int b)
    {
        int roota = find(a), rootb = find(b); if(sz[roota] > sz[rootb]) swap(roota, rootb); parent[roota] = rootb; sz[rootb] += sz[roota];
    }
};

ll d(ll x, ll y)
{
    return (multx * x + multy * y) % MOD;
}

template <class T> void printvec(vector<T> a)
{
    for(T i : a) cout << i << " ";
    cout << endl;
}

int main()
{
    fastio

    if(fopen("walk.in", "r"))
    {
        freopen("walk.in","r",stdin);
        freopen("walk.out","w",stdout); 
    }

    // Implementation with Prim's algorithm
    int n, k; cin >> n >> k;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> dist(n + 1, INF);
    dist[0] = -1;
    pq.push({0, 1});
    vector<bool> v(n + 1);
    while(!pq.empty())
    {
        pll top = pq.top(); pq.pop();
        if(v[top.second]) continue;
        v[top.second] = true;
        for(ll i = 1; i <= n; i++)
        {
            if(v[i]) continue;
            int temp = d(min(top.second, i), max(top.second, i));
            if(temp < dist[i]) 
            {
                pq.push(mp(temp, i));
                dist[i] = temp;
            }
        }
    }
    dist[1] = multx;
    sort(all(dist)); 
    cout << dist[n - k + 1] << endl;
    printvec(dist);

    /* Implementation with Kruskal's algorithm */

    // vector<pipii> edges;
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = i + 1; j <= n; j++)
    //     {
    //         edges.pb(mp(d(i, j), mp(i, j)));
    //     }
    // }
    // sort(all(edges));
    // dsu d; d.init(n);
    // int idx = 0, tempk = n - k;
    // while(tempk > 0)
    // {
    //     pipii curr = edges[idx];
    //     if(d.find(curr.second.first) == d.find(curr.second.second)) idx++;
    //     else
    //     {
    //         idx++; tempk--;
    //         d.merge(curr.second.first, curr.second.second);
    //     }
    // }

    // ll mn = 1e15;
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = i + 1; j <= n; j++)
    //     {
    //         if(d.parent[i] != d.parent[j])
    //         {
    //             mn = min(mn, (multx * i + multy * j) % MOD);
    //         }
    //     }
    // }
    // cout << mn << endl;

    
}
