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

bool cmp()
{
    return 0;
}

void solve()
{
    int n, k; cin >> n >> k;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    int count = 0;
    string curr;
    for(int i = 0; i < n; i++)
    {
        if(count + s[i].size() <= k)
        {
            if(curr.size() > 0) curr += " ";
            curr += s[i];
            count += s[i].size();
        }
        else
        {
            count = s[i].size();
            cout << curr << "\n";
            curr = s[i];
        }
    }
    cout << curr << "\n";
}

int main()
{
    fastio

    if(fopen("word.in", "r"))
    {
        freopen("word.in", "r", stdin);
        freopen("word.out", "w", stdout);
    }

    solve();
}
