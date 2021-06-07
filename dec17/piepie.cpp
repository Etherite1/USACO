#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define plpll pair<long long, pair<long long, long long>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vii vector<pii>
#define vll vector<pll>
#define vl vector<long long>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()
#define rsz resize
#define sz(a) ((int)(a).size())

#ifdef Etherite_Local
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.first << ", " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cerr << i << " "; cerr << endl;}
mt19937 rnd(228);
#else
#define DBG1(x)
#define DBG2(x, y)
#define DBG3(x, y, z)
#define DBG4(a, b, c, d)
template<class T> void DBGpair(T a, string s = "") {return;}
template <class T> void DBGvec(vector<T> &a){}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353
const ll INF = 1e9;

void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

#define pii pair<int, int>
#define piipi pair<pair<int, int>, int>

void solve()
{
    setIO("piepie");
    int n, d; cin >> n >> d;
    vector<pii> a(n), b(n); 
    for(auto &i : a) cin >> i.first >> i.second;
    for(auto &i : b) cin >> i.first >> i.second; 
    multiset<piipi> bes, els;
    queue<pii> q; // {current pie index, bessie or elsie}
    vector<int> ansa(n, -1), ansb(n, -1);
    for(int i = 0; i < n; i++)
    {
        if(a[i].second != 0) bes.insert({{a[i].second, a[i].first}, i});
        else q.push({i, 0}), ansa[i] = 1;
        if(b[i].first != 0) els.insert({b[i], i});
        else q.push({i, 1}), ansb[i] = 1;
    }
    while(!q.empty())
    {
        pii curr = q.front(); q.pop();
        pii pie; int idx = curr.first, type = curr.second;
        if(type == 0) // bessie
        {
            pie = a[idx];
            pie.second = 2e9;
            DBGpair(pie);
            while(1)
            {
                auto it = els.upper_bound({pie, -1});
                if(it == els.begin()) break;
                it--;
                if((*it).first.first < pie.first - d) break;
                q.push({(*it).second, 1});
                ansb[(*it).second] = ansa[idx] + 1;
                els.erase(it);
            }
        }
        else // elsie
        {
            pie = b[idx];
            swap(pie.first, pie.second);
            pie.second = 2e9;
            DBGpair(pie);
            while(1)
            {
                auto it = bes.upper_bound({pie, -1});
                if(it == bes.begin()) break;
                it--;
                if((*it).first.first < pie.first - d) break;
                q.push({(*it).second, 0});
                ansa[(*it).second] = ansb[idx] + 1;
                bes.erase(it);
            }
        }
    }
    for(auto i : ansa) cout << i << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
