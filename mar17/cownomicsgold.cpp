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

vector<string> a, b;
int n, m;

bool chk(int len)
{
    set<string> x, y;
    for(int i = 0; i < m; i++)
    {
        if(i + len > m) break;
        for(int j = 0; j < n; j++)
        {
            x.insert(a[j].substr(i, len));
            y.insert(b[j].substr(i, len));
        }
        bool flag = 1;
        for(auto i : x) 
        {
            if(y.find(i) != y.end()) flag = 0;
        }
        if(flag) return 1;
        x.clear(); y.clear();
    }
    return 0;
}

void solve()
{
    setIO("cownomics");
    cin >> n >> m;
    a.resize(n); b.resize(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    int l = 0, r = m + 1;
    while(r - l > 1)
    {
        int mid = (l + r) / 2;
        if(chk(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();
}
