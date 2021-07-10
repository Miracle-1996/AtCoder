#include <bits/stdc++.h>
#include <atcoder/all>
#define hash _hash
#define endl '\n'
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define cal1(x) __builtin_popcount(x)
using namespace std;
using namespace atcoder;
using ll = int64_t;
using int128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;

const ld pi = M_PI;
const int N = 1e5 + 10;
const int M = 2 * N;
const int lgN = 20;
string str; int n, m, c[N], d[N], v[N];
int ver[M], nxt[M], head[N], idx;
int lg2[N], f[N][lgN], dep[N], dist[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

void add(int x, int y) 
{ 
	ver[++idx] = y; nxt[idx] = head[x]; head[x] = idx; 
}

void bfs(int u)
{
    memset(f, 0, sizeof(f)); 
    memset(dep, 0, sizeof(dep));
    queue<int> q; q.push(u); dep[u] = 1;
    while (q.size()) {
        int x = q.front(); q.pop();
        for (int k = head[x]; k; k = nxt[k]) {
            int y = ver[k];
            if (dep[y]) continue; 
            dep[y] = dep[x] + 1;
            dist[y] = dist[x] + 1;
            f[y][0] = x; 
            for (int i = 1; i <= lg2[n]; ++i) f[y][i] = f[f[y][i - 1]][i - 1]; 
            q.push(y);
        }
    }
}

int lca(int x, int y)
{
    if (dep[x] < dep[y]) swap(x, y);
    for (int k = lg2[n]; k >= 0; --k) {
        if (dep[f[x][k]] >= dep[y]) x = f[x][k];
    }
    if (x == y) return y;
    for (int k = lg2[n]; k >= 0; --k) {
        if (f[x][k] != f[y][k]) { x = f[x][k]; y = f[y][k]; }
    }
    return f[x][0];
}

void solve(int x, int y)
{	
	for (int k = 1; k <= n; ++k) {
		int val = dist[x] + dist[y] - 2 * dist[lca(x, y)];
		cout << ((val & 1) ? "Road" : "Town") << endl;
	}
}

void dfs(int x, int color)
{
	v[x] = color;
	for (int k = head[x]; k; k = nxt[k]) {
		int y = ver[k];
		if (v[y]) continue;
		dfs(y, 3 - color);
	}
}

void solution(void)
{
	memset(v, 0, sizeof(v));
	dfs(1, 1);
	for (int k = 1; k <= m; ++k) {
		cout << ((v[c[k]] == v[d[k]]) ? "Town" : "Road") << endl;
	}
}

signed main(int argc, char** argv)
{
	#ifdef Miracle
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	lg2[1] = 0;
    for (int k = 2; k <= n; ++k) lg2[k] = lg2[k >> 1] + 1;
	while (cin >> n >> m) {
		for (int k = 1; k <= n - 1; ++k) {
			int x, y; cin >> x >> y;
			add(x, y); add(y, x);
		}
		bfs(1);
		for (int k = 1; k <= m; ++k) cin >> c[k] >> d[k];
		solution();
		memset(head, 0, sizeof(head)); idx = 0;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}
// type: tree

/* tips */
/*
	tree's property : bipartiteness
*/

/* editorial */
/*
	bipartiteness of trees + color 
*/

/* question */
/*
*/