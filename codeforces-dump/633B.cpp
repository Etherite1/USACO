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
#define forrange(i, x) for(int i = 0; i < x; i++)
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

int f(int i) {
	int r = 0;
	while(i) {
		r += i / 5;
		i /= 5;
	}
	return r;
}
 
int main() {
	int m;
	cin >> m;
	vi w;
	for(int i = 0; i <= 1000000; i++) if(f(i) == m) w.pb(i);
	cout << w.size() << endl;
	for(int a : w) cout << a << " ";
	puts("");
	return 0;
}
