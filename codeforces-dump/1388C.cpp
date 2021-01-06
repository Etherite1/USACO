#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

vector < int > gr[N];

bool access = true;

int p[N], h[N], a[N], g[N];

void dfs(int v, int ancestor = -1) {
    a[v] = p[v];
    int sum_g = 0;
    for (int to : gr[v]) {
        if (to == ancestor) continue;
        dfs(to, v);
        sum_g += g[to];
        a[v] += a[to];
    }
    if ((a[v] + h[v]) % 2 == 0) {} // first
    else access = false;
    g[v] = (a[v] + h[v]) / 2;
    if (g[v] >= 0 && g[v] <= a[v]) {} // second
    else access = false;
    if (sum_g <= g[v]) {} // third
    else access = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) cin >> h[i];
        for (int i = 0; i < n - 1; ++i) {
            int a, b; cin >> a >> b;
            --a, --b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        dfs(0);
        cout << (access ? "YES" : "NO") << endl;
        access = true;
        for (int i = 0; i < n; ++i) gr[i].clear();
    }
}