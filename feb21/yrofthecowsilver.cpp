#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define vi vector<int>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()



int aceil(ll a, ll b)
{
    return (a + b - 1) / b;
}

void solve()
{
    int n, k; cin >> n >> k;
    vi a(n); for(auto &i : a) cin >> i;
    set<int> s;
    for(int i : a)
    {
        s.insert((i / 12) * 12);
        s.insert(aceil(i, 12) * 12);
        s.insert(i);
    }
    a.clear(); a.pb(0); for(auto i : s) a.pb(i);
    vi diffs;
    for(int i = 0; i < a.size() - 1; i++)
    {
        if(a[i] % 12 == 0 && a[i + 1] % 12 == 0) diffs.pb(a[i + 1] - a[i]);
    }
    sort(rall(diffs));
    int sum = 0;
    for(int i = 0; i < min(k - 1, (int) diffs.size()); i++) sum += diffs[i];
    cout << a.back() - sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}
