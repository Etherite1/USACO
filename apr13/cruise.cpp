#include "bits/stdc++.h"

using namespace std;

const int N = 1050;
int l[N], r[N], fin[N], vis[N], dist[N];

// l is left edge, r is right edge
// fin[i] = position of i after string of moves

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

void solve()
{
    setIO("cruise");
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
    for(int i = 0; i < n; i++) l[i]--, r[i]--;
    vector<int> dir(m);
    for(int i = 0; i < m; i++)
    {
        char x; cin >> x;
        if(x == 'L') dir[i] = 0;
        else dir[i] = 1;
    }
    for(int i = 0; i < n; i++) // computing fin[i]
    {
        int cnode = i;
        for(auto move : dir) 
        {
            if(move) cnode = r[cnode];
            else cnode = l[cnode];
        }
        fin[i] = cnode;
    }
    int clen = 0, cnode = 0;
    while(1) // calculating length of a cycle
    {
        vis[cnode] = 1;
        if(vis[fin[cnode]]) 
        {
            clen = dist[cnode] - dist[fin[cnode]] + 1;
            k -= dist[fin[cnode]];
            break;
        }
        dist[fin[cnode]] = dist[cnode] + 1;
        cnode = fin[cnode];
    }
    cnode = fin[cnode];
    assert(clen);
    k %= clen;
    // cout << k << " " << cnode << endl;
    while(k--) cnode = fin[cnode];
    cout << cnode + 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
