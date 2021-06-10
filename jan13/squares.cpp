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
    setIO("squares");
    int n, k; cin >> n >> k;
    vector<pii> a(n);
    for(auto &i : a) cin >> i.first >> i.second;
    sort(a.begin(), a.end());
    bool flag = 0;
    int x = 0, y = 0;
    for(int i = 0; i < n; i++)
    {
        int j = i + 1;
        while(1)
        {
            if(j >= n || (a[j].first - a[i].first) >= k) break;
            if(abs(a[j].second - a[i].second) < k)
            {
                if(flag) {cout << "-1\n"; return;}
                flag = 1;
                x = a[j].first - a[i].first, y = abs(a[j].second - a[i].second);
            }
            j++;
        }
    }
    if(!flag) cout << "0\n";
    else cout << ((x - k) * (y - k)) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
