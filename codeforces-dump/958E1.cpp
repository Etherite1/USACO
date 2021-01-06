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
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
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

ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}

template <class T> void printvec(vector<T> a)
{
    for(T i : a) cout << i << " ";
    cout << endl;
}

ll aceil(ll num, ll denom)
{
    return (num + denom - 1) / denom;
}

vector<ll> divs;
void getdiv(int n) 
{ 
    for(int i = 1; i * i <= n; i++) 
    { 
        if(n % i == 0) 
        { 
            if(n / i == i) divs.push_back(i);
            else divs.pb(i), divs.pb(n / i);
        } 
    } 
} 

bool cmp()
{
    return 0;
}

// Returns 1 if the lines intersect, otherwise 0. In addition, if the lines 
// intersect the intersection point may be stored in the floats i_x and i_y.
bool inter(float p0_x, float p0_y, float p1_x, float p1_y, 
    float p2_x, float p2_y, float p3_x, float p3_y)
{
    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1) return 1;
    else return 0; // No collision
}

bool chk(vii ship, vii base, int n)
{
    for(int i = 0; i < n; i++) // first check 0, 0 paired, then check all others
    {
        for(int j = 0; j < n; j++)
        {
            if(j == i) continue;
            if(inter(ship[i].first, ship[i].second, base[i].first, base[i].second, ship[j].first, ship[j].second, base[j].first, base[j].second)) return 0;
        }
    }
    return 1;
}

bool isprime(ll n) 
{ 
    if(n <= 1) return 0; 
	if(n <= 3) return 1; 
	if(n % 2 == 0 || n % 3 == 0) return 0; 
	for(long long i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i+2) == 0) return 0; 
	return 1; 
} 
	 
bitset<15000150> prime; 
void sieve(int n) 
{ 
	for(long long i = 0; i <= n; i++) prime[i] = 1;
	for(long long p = 2; p * p <= n; p++) 
    { 
        if(prime[p]) 
        { 
            for(long long i = p * p; i <= n; i += p) prime[i] = false; 
        } 
	} 
	prime[1] = prime[0] = 0;
} 
	 
vector<long long> primelist;
bool __primes_generated__ = 0;
	 
void genprimes(int n) 
{
    __primes_generated__ = 1;
    sieve(n + 1);
    for(long long i = 2; i <= n; i++) if (prime[i]) primelist.pb(i);
}
	 
vector<long long> factors(long long n) 
{
    if(!__primes_generated__) 
    {
        cout << "Call genprimes you dope" << endl;
        exit(1);
    }
    vector<long long> facs;

    for(long long i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) 
    {
        if(n % primelist[i] == 0) 
        {
            while (n % primelist[i] == 0) 
            {
                n /= primelist[i];
                facs.push_back(primelist[i]);
            }
        }
    }
    if(n > 1) facs.push_back(n);
    sort(facs.begin(), facs.end());
    return facs;
}

void solve()
{
    int r, b; cin >> r >> b;
    if(r != b) {cout << "No\n"; return;}   
    int n = r;
    vii ship(n), base(n);
    for(int i = 0; i < n; i++) cin >> ship[i].first >> ship[i].second;
    for(int i = 0; i < n; i++) cin >> base[i].first >> base[i].second;
    if(chk(ship, base, n)) {cout << "Yes\n"; return;}
    while(next_permutation(all(base)))
    {
        if(chk(ship, base, n)) {cout << "Yes\n"; return;}
    }
    cout << "No\n"; return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
