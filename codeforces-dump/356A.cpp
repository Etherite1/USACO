#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 2;

int n, m, index = 1;
int t[2 * N], d[2 * N];
int chl[2 * N], chr[2 * N];
int l[N], r[N], x[N];

void push(int v, int tl, int tr) {
	if (d[v] == -1) {
		return;
	}
	t[v] = (tr - tl + 1) * d[v];
	if (tl != tr) {
		if (chl[v] == 0) {
			chl[v] = ++index;
		}
		d[chl[v]] = d[v];
		if (chr[v] == 0) {
			chr[v] = ++index;
		}
		d[chr[v]] = d[v];
	}
	d[v] = -1;
}

int query(int l, int r, int v = 1, int tl = 1, int tr = n) {
	push(v, tl, tr);
	if (tl == l && tr == r) {
		return t[v];
	}
	int tm = (tl + tr) / 2;
	if (r <= tm) {
		return query(l, r, chl[v], tl, tm);
	}
	else if (l > tm) {
		return query(l, r, chr[v], tm + 1, tr);
	}
	else {
		return query(l, tm, chl[v], tl, tm) +
			query(tm + 1, r, chr[v], tm + 1, tr);
	}
}

void update(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	push(v, tl, tr);
	if (tl == l && tr == r) {
		d[v] = x;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) / 2;
	if (chl[v] == 0) {
		chl[v] = ++index;
	}
	if (chr[v] == 0) {
		chr[v] = ++index;
	}
	if (r <= tm) {
		update(l, r, x, chl[v], tl, tm);
	}
	else if (l > tm) {
		update(l, r, x, chr[v], tm + 1, tr);
	}
	else {
		update(l, tm, x, chl[v], tl, tm);
		update(tm + 1, r, x, chr[v], tm + 1, tr);
		t[v] = t[chl[v]] + t[chr[v]];
	}
}

int main() 
{
	fill(d, d + 2 * N, -1);
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> l[i] >> r[i] >> x[i];
	for (int i = m - 1; i >= 0; i--) 
    {
		if (x[i] != l[i]) update(l[i], x[i] - 1, x[i]);
		if (x[i] != r[i]) update(x[i] + 1, r[i], x[i]);
	}
	for (int i = 1; i <= n; i++) cout << query(i, i) << " ";
	cout << endl;
}