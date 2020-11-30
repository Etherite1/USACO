#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second

const int MOD = 1e9+7; 

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

struct mi {
    int v; explicit operator int() const { return v; }
    mi(ll _v) : v(_v%MOD) { v += (v<0)*MOD; }
    mi() : mi(0) {}
};
mi operator+(mi a, mi b) { return mi(a.v+b.v); }
mi operator-(mi a, mi b) { return mi(a.v-b.v); }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
 
int N;
vector<pair<int,int>> v;
vector<mi> sum[100005];
vector<pair<int,int>> todo[20001];
 
void check() 
{
	for (int i = 0; i <= 20000; ++i) 
        if (todo[i].size() > 0) // if there are segments starting here
        {
            int sz = todo[i].size();
            sort(begin(todo[i]), end(todo[i])); // sort the array so points are in order left to right
            mi cur = 0;
            for (int j = 0; j < sz; ++j) cur = cur + todo[i][j].f - todo[i][0].f; //sum of distances from point 0 (leftmost) to current point
            for (int j = 0; j < sz; ++j) 
            {
                if(j > 0) cur = cur + (2 * j - sz) * (todo[i][j].f - todo[i][j-1].f); // transition to next point, now corner fixed at jth point
                sum[todo[i][j].s].push_back(cur); // first value is x value, second value is y value
            }
	    }
}
 
int main() 
{
	setIO("triangles"); 
	cin >> N; v.resize(N); 
	for (int i = 0; i < N; ++i) cin >> v[i].f >> v[i].s; // read in input
	for (int i = 0; i <= 20000; ++i) todo[i].clear();
	for (int i = 0; i < N; ++i) todo[v[i].f + 10000].push_back({v[i].s, i}); // vertical points at same x value
	check();
	for (int i = 0; i <= 20000; ++i) todo[i].clear();
	for (int i = 0; i < N; ++i) todo[v[i].s + 10000].push_back({v[i].f, i}); // vertical points at same y value
	check();
	mi ans = 0; 
	for (int i = 0; i < N; ++i) ans = ans + sum[i][0] * sum[i][1]; // x segments * y segments
	cout << ans.v << "\n";
}