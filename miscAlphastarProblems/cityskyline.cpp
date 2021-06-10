#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define endl "\n"

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
    int n, w; cin >> n >> w;
    vector<int> a(n);
    for(auto &i : a) cin >> i >> i;
    stack<int> stk;
    stk.push(0);
    int ans = 0;
    for(int i : a)
    {
        while(!stk.empty() && i < stk.top()) stk.pop();
        if(i > stk.top()) ans++;
        stk.push(i);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
