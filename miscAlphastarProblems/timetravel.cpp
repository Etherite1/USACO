#include "bits/stdc++.h"

using namespace std;

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
    setIO("ttravel");
    int n; cin >> n;
    map<int, int> par, top;
    int cnode = -1, qnum = 1;
    top[0] = -1;
    while(n--)
    {
        char t; cin >> t;
        if(t == 'a')
        {
            int x; cin >> x;
            top[qnum] = x;
            par[qnum] = qnum - 1;
        }
        else if(t == 's') 
        {
            top[qnum] = top[par[qnum - 1]];
            par[qnum] = par[par[qnum - 1]];
        }
        else
        {
            int x; cin >> x;
            top[qnum] = top[x - 1];
            par[qnum] = par[x - 1];
        }
        cout << top[qnum] << endl;
        qnum++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}
