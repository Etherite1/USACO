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

int n, m;

bool cmp()
{
    return 0;
}

bool find(int minsize, vector<pipii> whs, vi orig)
{
    vvi adj(n);
    for(pipii i : whs)
    {
        if(i.first < minsize) continue;
        adj[i.second.first].pb(i.second.second);
        adj[i.second.second].pb(i.second.first);
    }
    vi compnums(n);
    int currcomp = 0;
    vb v(n);
    for(int i = 0; i < n; i++)
    {
        if(v[i]) continue; v[i] = true;
        currcomp++;
        compnums[i] = currcomp;
        queue<int> q; q.push(i);
        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            compnums[curr] = currcomp;
            for(int adjnode : adj[curr])
            {
                if(v[adjnode]) continue;
                v[adjnode] = true;
                q.push(adjnode);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(compnums[i] == compnums[orig[i]]) continue;
        else return false;
    }
    return true;
}

int main()
{
    fastio

    freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);

    cin >> n >> m;
    vi orig(n);
    for(int i = 0; i < n; i++) cin >> orig[i];
    for(int i = 0; i < n; i++) orig[i]--;

    bool sorted = 1;
    for(int i = 0; i < n; i++)
    {
        if(i != orig[i]) sorted = 0;
    }
    if(sorted)
    {
        cout << "-1\n";
        return 0;
    }

    vector<pipii> whs(m);
    int maxW = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> whs[i].second.first >> whs[i].second.second >> whs[i].first;
        whs[i].second.first--; whs[i].second.second--;
        maxW = max(maxW, whs[i].first);
    }

    int l = 0, r = maxW + 1;
    while(r - l > 1)
    {
        int mid = (l + r) / 2; // mid is smallest wormhole that the cows will go into
        if(find(mid, whs, orig)) l = mid;
        else r = mid;
    }

    cout << l << endl;
}
