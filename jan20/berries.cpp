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

int mod = 0;

bool cmp(int a, int b)
{
    return a % mod > b % mod;
}

int main()
{
    fastio

    freopen("berries.in","r",stdin);
    freopen("berries.out","w",stdout);

    int n, k; cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for(int i = 1; i <= 1000; i++)
    {
        int buckets = 0;
        for(int j : a) buckets += j / i;
        if(buckets < k / 2) break;
        if(buckets >= k)
        {
            ans = max(ans, i * (k / 2));
            continue;
        }
        mod = i;
        sort(all(a), cmp);
        int curr = i * (buckets - k / 2); 
        // size of each bucket times number of buckets we have times half of k; aka number of berries for bessie after elsie gets her share
        for(int j = 0; j < n && j + buckets < k; j++)
        {
            curr += a[j] % i;
        }
        ans = max(ans, curr);
    }

    cout << ans << endl;

}
