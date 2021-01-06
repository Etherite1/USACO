#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll N = 1e6;
 
using namespace std;
 
struct problem {
	ll p, t;
 
	bool operator < (const problem& b) const {
		return t < b.t;
	}
} v[N];
 
ll T, n, m, a, b, easy, hard;
 
int main () {
	cin >> m;
 
	while (m--) {
		cin >> n >> T >> a >> b;
		for (ll i = 0; i < n; i++) {
			cin >> v[i].p;
			if (v[i].p) hard++;
			else easy++;
		}
 
		for (ll i = 0; i < n; i++) {
			cin >> v[i].t;
		}
 
		sort (v, v + n);
 
		ll x = 0, ans = 0;
 
		for (ll i = 0; i < n; i++) {
			ll time = v[i].t - 1 - x, pts = i;
 
			ll neasy = time / a;
 
			if (neasy >= easy) {
				pts += easy;
				time -= easy * a;
				ll nhard = time / b;
				pts += nhard;
			} else {
				pts += neasy;
			}
 
			if (v[i].t - 1 - x >= 0) ans = max (ans, pts);
			
			if (v[i].p) {
				hard--;
				x += b;
			}
			else {
				x += a;
				easy--;
			}
		}
 
		if (T - x >= 0) ans = n;
 
		cout << ans << '\n';
	}
}