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

struct Entry {
  int index;
  int value;
};

bool cmp(Entry a, Entry b)
{
    if(a.value == b.value) return a.index < b.index;
      else return a.value < b.value;
}

int main() {
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    int n; fin >> n;
    vector<Entry> entries(n);

    for (int i = 0; i < n; i++) {
      entries[i].index = i;
      fin >> entries[i].value;
    }

    sort(all(entries), cmp);
      // Break ties by making the smaller element be whichever
      // element was first in the array originally.

    int ans = 0;
    for (int j = 0; j < n; j++) {
      // In terms of the notation from the above analysis, we have,
      // entries[j].index = i
      // j = a_i
      ans = max(ans, entries[j].index - j);
    }

    fout << ans + 1;
}
