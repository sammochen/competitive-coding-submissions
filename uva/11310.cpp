#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

VVLL dp(50, VLL(2, -1));
ll get(ll x, ll fill) {
	if (x < 0) return 0;
	if (x == 0 && fill == 0) return 1;
	if (x == 0 && fill == 1) return 0;
	if (dp[x][fill] != -1) return dp[x][fill];

	ll ans = 0;
	if (fill == 0) {
		// fill both up with 1s
		ans += get(x-1, 0);
		// fill it with a 3 (both orientations)
		ans += 2 * get(x-1, 1);
		// fill with a 1-3 square
		ans += 2 * get(x-2, 0);
	} else {
		// fill it with a 1
		ans += get(x-1, 0);
		// fill it with a triangle
		ans += get(x-2, 0);
	}
	dp[x][fill] = ans;
	return ans;
}
void solve() {
	ll n;
	cin >> n;
	cout << get(n, 0) << endl;
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}