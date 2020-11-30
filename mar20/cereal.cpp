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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
    for(T i : a) cout << i << " ";
    cout << endl;
}

bool cmp()
{
    return 0;
}
vii cows;
map<int, pair<int, int>> choices; // first is cereal type, second.first is index, second.second is favorite or second fav cereal

void change(pii types, int curridx) // inserts pair and kicks out other pairs
{
    if(choices.find(types.first) == choices.end()) 
    {
        choices[types.first] = mp(curridx, 1);
        return;
    }
    else
    {
        auto other = choices[types.first]; // cow that we are kicking out
        //kick it out if we have higher priority
        if(curridx < other.first)
        {
            choices[types.first] = mp(curridx, 1);
            change(cows[other.first], other.first);
        }
        // go to second choice
        else
        {
            if(choices.find(types.second) == choices.end())
            {
                choices[types.second] = mp(curridx, 2);
                return;
            }
            else
            {
                auto o = choices[types.second];
                if(curridx < o.first)
                {
                    choices[types.second] = mp(curridx, 2);
                    change(cows[o.first], o.first);
                }
            }
        }
    }
    
}

void solve()
{
    setIO("cereal");
    int n, m; cin >> n >> m;
    cows.resize(n);
    rep(i, 0, n) cin >> cows[i].first >> cows[i].second;
    vi ans;
    for(int i = n - 1; i >= 0; i--)
    {
        change(cows[i], i);
        ans.pb(choices.size());
    }
    reverse(all(ans));
    for(int i : ans) cout << i << endl;

    // set<int> used;
    // rep(i, 0, n)
    // {
    //     rep(c, 1, m + 1) used.insert(c);
    //     int cnt = 0;
    //     rep(j, i, n)
    //     {
    //         if(used.find(cows[j].first) != used.end()) used.erase(cows[j].first), cnt++;
    //         else if(used.find(cows[j].second) != used.end()) used.erase(cows[j].second), cnt++;
    //     }
        
    //     cout << cnt << endl;
    //     used.clear();
    // }   



}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
