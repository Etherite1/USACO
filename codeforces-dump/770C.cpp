#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vl vector<long long>
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pf push_front
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i, begin, end) for(int i = begin; i < end; i++)
#define brep(i, end, begin) for(int i = end; i > begin; i--)
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()
#define watch(x) cout << (#x) << " is " << (x) << endl

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

template <class T> void printvec(vector<T> a)
{
    for(T i : a) cerr << i << " ";
    cerr << endl;
}

bool cmp()
{
    return 0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    // input
    ll N,K;
    cin>>N>>K;
 
    vi S(K); // specialty
    rep(i,0, K){
      cin>>S[i];
      S[i]--;
    }
 
    vvi G(N);
 
    rep(i,0, N){
      ll n;cin>>n;
      while(n--){
        ll a;cin>>a;a--;
        G[i].push_back(a);
      }
    }
    vi color(N);
    vi ord;
    
    bool cycle=false;
    function<void(ll)> dfs = [&](ll u){
      if(color[u]==0){
        color[u]=1;
        for(ll to : G[u]){
          dfs(to);
        }
        ord.push_back(u);
        color[u]=2;
      }else if(color[u]==1){
        cycle = true;
      }
    };
 
    for(ll s : S) dfs(s);
 
    if(cycle){
      cout << -1;return 0;
    }
    cout << ord.size() << endl;
    for(int i : ord) cout << i + 1 << " ";
    
    return 0;
}
