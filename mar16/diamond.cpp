#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vb vector<bool>
#define vl vector<long long>
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353

int main()
{
    fastio

    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int n, k; fin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) fin >> a[i];
    sort(all(a));

    vi goingleft(n), goingright(n);
    for(int i = 0; i < n; i++)
    {
        int l = i, r = n; //goingright
        while(r - l > 1)
        {
            int mid = (l + r) / 2;
            if(a[mid] <= a[i] + k) l = mid;
            else r = mid;
        }
        goingright[i] = r - i;

        if(i - 1 < 0) continue;
        l = 0; r = i;
        while(r - l > 1) //goingleft
        {
            int mid = (l + r) / 2;
            if(a[mid] >= a[i] - k) r = mid;
            else l = mid;
        }
        goingleft[i - 1] = i - r + 1;
    }

    vi left(n), right(n);

    left[0] = goingleft[0];
    right[n - 1] = goingright[n - 1];
    for(int i = 1; i < n; i++)
    {
        left[i] = max(goingleft[i], left[i - 1]);
    }
    for(int i = n - 2; i >= 0; i--)
    {
        right[i] = max(goingright[i], right[i + 1]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, left[i] + right[i]);
    }
    if(ans > n) ans = n;
    fout << ans << endl;
   
}
