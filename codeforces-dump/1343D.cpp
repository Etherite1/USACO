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
#define rep(i, x, y) for(int (i) = (x); i < (y); i++)
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353
const int INF = 1e9;

template <class T> void printvec(vector<T> a)
{
    for(T i : a) cout << i << " ";
    cout << endl;
}

struct event{int x; bool left;};

bool cmp(event x, event y)
{
    return x.x < y.x;   
}

bool inrange(pii a, int x)
{
    if(x >= a.first && x <= a.second) return 1;
    else return 0;
}

void solve()
{

    int n, k;
	cin >> n >> k;
	vi a(n), v;
 
	for(int i = 0; i < n; i++)
		cin >> a[i];
 
	for(int i = 0; i < n/2; i++) {
		int sum = a[i] + a[n - 1 - i];
		int m = sum - max(a[i], a[n - 1 - i]) + 1,
				M = sum + k - min(a[i], a[n - 1 - i]); //with one change, we can change sum to any value from [m, M]
		M++;
		//answer only changes at points x = m, M or sum
		v.pb(m), v.pb(M), v.pb(sum);
	}
 
	sort(all(v)); // perform compression
	v.resize(unique(all(v)) - v.begin()); // of size < 4n
	vi pref(4*n), cnt(4*n);
 
	for(int i = 0; i < n/2; i++) {
		int sum = a[i] + a[n - 1 - i];
		int m = sum - max(a[i], a[n - 1 - i]) + 1,
			M = sum + k - min(a[i], a[n - 1 - i]);
		M++;
		int m_comp = lower_bound(all(v), m) - v.begin(); //compressed m
		int M_comp = lower_bound(all(v), M) - v.begin(); //compressed M
		pref[m_comp]++;
		pref[M_comp]--;
		int sum_comp = lower_bound(all(v), sum) - v.begin(); //compressed sum
		cnt[sum_comp]++;
	}
 
	for(int i = 1; i < pref.size(); i++)
		pref[i] += pref[i - 1];
 
	int res = 1e15;
 
	for(int i = 0; i < 4*n; i++) {
		int ans = pref[i] - cnt[i] + 2*(n/2 - pref[i]);
		res = min(res, ans); 
	}
 
	cout << res << '\n';
    // int n, k; cin >> n >> k;
    // vi a(n); rep(i, 0, n) cin >> a[i];
    // vector<event> ends;
    // rep(i, 0, n / 2)
    // {
    //     event f1, f2, s1, s2;
    //     f1.x = (a[i] + 1); f1.left = 1;
    //     f2.x = (a[i] + k); f2.left = 0;
    //     s1.x = (1 + a[n - i - 1]); s1.left = 1;
    //     s2.x = (k + a[n - i - 1]); s2.left = 0;
    //     ends.pb(f1); ends.pb(f2); ends.pb(s1); ends.pb(s2);
    // }
    // sort(all(ends), cmp);

    // int curr = 0, maxnum = 0, maxcnt = 0;
    // for(event i : ends)
    // {
    //     if(i.left)
    //     {
    //         curr++;
    //         if(curr >= maxcnt)
    //         {
    //             maxnum = i.x;
    //             maxcnt = curr;
    //         }
    //     }
    //     else
    //     {
    //         curr--;
    //     }
    // }
    // int ans = 0;
    // rep(i, 0, n / 2)
    // {
    //     if(a[i] + a[n - i - 1] == maxnum) continue;
    //     else
    //     {
    //         // check if within k distance
    //         pii range1, range2;
    //         range1 = {a[n - i - 1] + 1, k + a[n - i - 1]};
    //         range2 = {a[i] + 1, a[i] + k};
    //         if(inrange(range1, maxnum) || inrange(range2, maxnum)) ans++;
    //         else ans += 2;
    //     }
    // }
    // cout << ans << endl;
}

int main()
{
    fastio

    if(fopen("file.in", "r"))
    {
        freopen("file.in","r",stdin);
        freopen("file.out","w",stdout);
    }

    int t = 1;
    cin >> t;

    while(t-- > 0) solve();
}
