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

const int MAXN = 100001;

vector<int> parent(MAXN);
vector<int> sz(MAXN);

void initialize()
{
    for(int i = 0; i < MAXN; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int x)
{
    if(parent[x] == x) return x;
    else
    {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void merge(int a, int b)
{
    int roota = find(a), rootb = find(b);
    if(sz[roota] > sz[rootb]) swap(roota, rootb);
    parent[roota] = rootb;
    sz[rootb] += sz[roota];
}

int main()
{
    fastio

    if(fopen("file.in", "r"))
    {
        freopen("file.in","r",stdin);
        freopen("file.out","w",stdout);
    }

    


}
