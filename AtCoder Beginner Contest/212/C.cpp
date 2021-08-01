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
const int N = 2e5 + 10;
string str; int n, m, a[N], b[N];

template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }

template <class T> T search1(T l, T r, const T& x)
{
	while (l < r) {
		T mid = l + (r - l) / 2;
		(b[mid] >= x) ? r = mid : l = mid + 1;
	}
	return b[r];
}

template <class T> T search2(T l, T r, const T& x)
{
	while (l < r) {
		T mid = l + (r - l + 1) / 2;
		(b[mid] <= x) ? l = mid : r = mid - 1;
	}
	return b[l];
}

template <class T> T lower(T l, T r, const T& x)
{
	while (l + 1 < r) {
		T mid = l + (r - l) / 2;
		(b[mid] >= x) ? r = mid : l = mid;
	}
	return b[r];
}

template <class T> T upper(T l, T r, const T& x)
{
	while (l + 1 < r) {
		T mid = l + (r - l) / 2;
		(b[mid] <= x) ? l = mid : r = mid;
	}
	return b[l];
}

int solve(void)
{
	int res = INT_MAX;
	sort(b + 1, b + m + 1);
	b[0] = b[1];// <= a[k]情况下找不到,返回b[0]的边界情况处理
	for (int k = 1; k <= n; ++k) {
		// int val1 = search1(1, m, a[k]);
		// int val2 = search2(1, m, a[k]);

		// (1, 4)->WA
		// int val1 = *upper_bound(b + 1, b + m + 1, a[k]);
		// int val1 = *lower_bound(b + 1, b + m + 1, a[k]);
		// int val2 = *(upper_bound(b + 1, b + m + 1, a[k]) - 1);
		// int val2 = *(lower_bound(b + 1, b + m + 1, a[k]) - 1);

		int val1 = lower(0, m, a[k]);
		int val2 = upper(1, m + 1, a[k]);
		int x = min(abs(a[k] -val1), abs(a[k] - val2));
		chmin(res, x);
	}
	return res;
}

int solution(void)
{
	int res = INT_MAX;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	for (int l = 1, r = 1; l <= n; ++l) {
		while (r <= m && a[l] > b[r]) { 
			chmin(res, abs(a[l] - b[r])); ++r; 
		}
		if (r <= m && a[l] <= b[r]) chmin(res, abs(a[l] - b[r]));
	}
	return res;
}

signed main(int argc, char** argv)
{
	#ifdef Miracle
		auto start_clock = clock();
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	cout << fixed << setprecision(20);
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n >> m) {
		for (int k = 1; k <= n; ++k) cin >> a[k];
		for (int k = 1; k <= m; ++k) cin >> b[k];
		cout << solution() << endl;
	}
	#ifdef Miracle
        auto end_clock = clock();
        cout << end_clock - start_clock << "ms" << endl;
    #endif
	return 0;	
}